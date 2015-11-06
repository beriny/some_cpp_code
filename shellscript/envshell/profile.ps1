# profile.ps1 name $myprofile
# %UserProfile%\My Documents\WindowsPowerShell\profile.ps1 
# This profile applies only to the current user, but affects all shells. 


Import-Module PSReadline

# Load posh-git module from current directory
Import-Module posh-git

Set-PSReadLineOption -HistorySearchCursorMovesToEnd 

# Set-PSReadlineKeyHandler -Key Tab -Function Complete
Set-PSReadlineKeyHandler -Key UpArrow -Function HistorySearchBackward
Set-PSReadlineKeyHandler -Key DownArrow -Function HistorySearchForward


#Import-VisualStudioVars -VisualStudioVersion 2013 -Architecture x86
Import-VisualStudioVars -VisualStudioVersion 2010 -Architecture x86


Set-Alias vi  "C:\Program Files\Git\usr\bin\vim.exe"
Set-Alias vim "C:\Program Files\Git\usr\bin\vim.exe"

$desktop = "$HOME/Desktop"
$download = "$HOME/Downloads"

$myprofile = "$HOME\Documents\WindowsPowerShell\profile.ps1"

# PowerShell Prompt Set Begin

# Get full name of user
$username = [Environment]::UserName
$hostname = $env:COMPUTERNAME

# Am I an admin?
$wid = [System.Security.Principal.WindowsIdentity]::GetCurrent()
$prp = new-object System.Security.Principal.WindowsPrincipal($wid)
$adm = [System.Security.Principal.WindowsBuiltInRole]::Administrator
$IsAdmin = $prp.IsInRole($adm)

# Function to write git repository status on prompt
function writegitprompt($status){
    if ($status) {
         write-host ' (' -nonewline 
         write-host ($status.Branch) -nonewline -foregroundcolor Cyan
         write-host ' ' -nonewline 
         if($status.HasWorking) {
             write-host "$([char]0x25CF)" -nonewline -ForegroundColor @{$true='Green';$false='DarkGray'}[$status.Working.Added -and $status.Working.Added.Count -ge 0]
             write-host "$([char]0x25CF)" -nonewline -ForegroundColor @{$true=(@{$true='Red';$false='Yellow'}[$status.Working.Unmerged -and $status.Working.Unmerged.Count -ge 0]);$false=(@{$true='Red';$false='DarkGray'}[$status.Working.Unmerged -and $status.Working.Unmerged.Count -ge 0])}[$status.Working.Modified -and $status.Working.Modified.Count -ge 0]
             write-host "$([char]0x25CF)" -nonewline -ForegroundColor @{$true='Red';$false='DarkGray'}[$status.Working.Deleted -and $status.Working.Deleted.Count -ge 0]
         } else {
             write-host "$([char]0x25CF)$([char]0x25CF)$([char]0x25CF)" -nonewline -ForegroundColor DarkGray
         }
         if($status.HasIndex) {
             write-host "| " -nonewline
             write-host "$([char]0x25CF)" -nonewline -ForegroundColor @{$true='Green';$false='DarkGray'}[$status.Index.Added -and $status.Index.Added.Count -ge 0]
             write-host "$([char]0x25CF)" -nonewline -ForegroundColor @{$true=(@{$true='Red';$false='Yellow'}[$status.Index.Unmerged -and $status.Index.Unmerged.Count -ge 0]);$false=(@{$true='Red';$false='DarkGray'}[$status.Working.Unmerged -and $status.Working.Unmerged.Count -ge 0])}[$status.Index.Modified -and $status.Index.Modified.Count -ge 0]
             write-host "$([char]0x25CF)" -nonewline -ForegroundColor @{$true='Red';$false='DarkGray'}[$status.Index.Deleted -and $status.Index.Deleted.Count -ge 0]
         }
         write-host ')' -nonewline		 
    }
}

function mypath__ {
	$mypath_ = $pwd.ProviderPath.Split('\')[-1]
	if (!$mypath_)
	{
		$mypath_ = $pwd.Drive.Root
	}
	if ($pwd.ProviderPath -eq $HOME)
	{
		$mypath_ = '~'
	}
	
	return $mypath_
}

<#
 # Copy from posh-git/GitUtils.ps1 function Get-GitStatus
 # #$stashCount = $null | git stash list 2>$null | measure-object | select -expand Count
 #>
 
function MyGet-GitStatus($gitDir = (Get-GitDirectory)) {
    $settings = $Global:GitPromptSettings
    $enabled = (-not $settings) -or $settings.EnablePromptStatus
	
    if ($enabled -and $gitDir)
    {
        if($settings.Debug) {
            $sw = [Diagnostics.Stopwatch]::StartNew(); Write-Host ''
        } else {
            $sw = $null
        }
		
        $branch = $null
        $aheadBy = 0
        $behindBy = 0
        $indexAdded = @()
        $indexModified = @()
        $indexDeleted = @()
        $indexUnmerged = @()
        $filesAdded = @()
        $filesModified = @()
        $filesDeleted = @()
        $filesUnmerged = @()
        $stashCount = 0		
						
		$status = git -c color.status=false status --short --branch 2>$null
				
		#$stashCount = $null | git stash list 2>$null | measure-object | select -expand Count
		
        $status | foreach {
            
            if($_) {
                switch -regex ($_) {
                    '^(?<index>[^#])(?<working>.) (?<path1>.*?)(?: -> (?<path2>.*))?$' {
                        switch ($matches['index']) {
                            'A' { $indexAdded += $matches['path1'] }
                            'M' { $indexModified += $matches['path1'] }
                            'R' { $indexModified += $matches['path1'] }
                            'C' { $indexModified += $matches['path1'] }
                            'D' { $indexDeleted += $matches['path1'] }
                            'U' { $indexUnmerged += $matches['path1'] }
                        }
                        switch ($matches['working']) {
                            '?' { $filesAdded += $matches['path1'] }
                            'A' { $filesAdded += $matches['path1'] }
                            'M' { $filesModified += $matches['path1'] }
                            'D' { $filesDeleted += $matches['path1'] }
                            'U' { $filesUnmerged += $matches['path1'] }
                        }
                    }

                    '^## (?<branch>\S+?)(?:\.\.\.(?<upstream>\S+))?(?: \[(?:ahead (?<ahead>\d+))?(?:, )?(?:behind (?<behind>\d+))?\])?$' {
                        $branch = $matches['branch']
                        $upstream = $matches['upstream']
                        $aheadBy = [int]$matches['ahead']
                        $behindBy = [int]$matches['behind']
                    }

                    '^## Initial commit on (?<branch>\S+)$' {
                        $branch = $matches['branch']
                    }
                }
            }
        }		
		
        if(!$branch) { 
			$branch = Get-GitBranch $gitDir $sw 			
		}
        
        $indexPaths = $indexAdded + $indexModified + $indexDeleted + $indexUnmerged
        $workingPaths = $filesAdded + $filesModified + $filesDeleted + $filesUnmerged
        $index = New-Object PSObject @(,@($indexPaths | ?{ $_ } | Select -Unique)) |
            Add-Member -PassThru NoteProperty Added    $indexAdded |
            Add-Member -PassThru NoteProperty Modified $indexModified |
            Add-Member -PassThru NoteProperty Deleted  $indexDeleted |
            Add-Member -PassThru NoteProperty Unmerged $indexUnmerged
        $working = New-Object PSObject @(,@($workingPaths | ?{ $_ } | Select -Unique)) |
            Add-Member -PassThru NoteProperty Added    $filesAdded |
            Add-Member -PassThru NoteProperty Modified $filesModified |
            Add-Member -PassThru NoteProperty Deleted  $filesDeleted |
            Add-Member -PassThru NoteProperty Unmerged $filesUnmerged
		
        $result = New-Object PSObject -Property @{
            GitDir          = $gitDir			
            Branch          = $branch
            AheadBy         = $aheadBy
            BehindBy        = $behindBy
            Upstream        = $upstream
            HasIndex        = [bool]$index
            Index           = $index
            HasWorking      = [bool]$working
            Working         = $working
            HasUntracked    = [bool]$filesAdded
            #StashCount      = $stashCount
        }
		
        return $result
    }
}

# Here we go
function global:prompt {
    $realLASTEXITCODE = $LASTEXITCODE
    if($IsAdmin){
        write-host $username -nonewline -ForegroundColor Red
    } else {
        write-host $username -nonewline -ForegroundColor Yellow
    }
    write-host " $([char]0x3C9) " -nonewline -ForegroundColor Gray
    #Write-Host($pwd.ProviderPath) -nonewline -ForegroundColor Green
	Write-Host(mypath__) -nonewline -ForegroundColor Green
    
    # writegitprompt (Get-GitStatus)
	writegitprompt (MyGet-GitStatus)	
    
    # Rightmost time display
    # Save cursor position first
    $saveY = [console]::CursorTop
    $saveX = [console]::CursorLeft
    $columns = (Get-Host).UI.RawUI.windowsize.width    # Column quantity of console window
    [console]::SetCursorPosition($columns - 10, $saveY)
    write-host "[" -nonewline
    write-host (Get-Date -format "HH:mm") -nonewline -ForegroundColor Cyan
    write-host "]" -nonewline
    [console]::setcursorposition($saveX, $saveY)        # Move cursor back

    $global:LASTEXITCODE = $realLASTEXITCODE
    return " $([char]0x3BB) "
}

# PowerShell Prompt Set End

Pop-Location
Start-SshAgent -Quiet

