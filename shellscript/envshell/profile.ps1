# profile.ps1 name $myprofile
# %UserProfile%\My Documents\WindowsPowerShell\profile.ps1 
# This profile applies only to the current user, but affects all shells. 

# Load posh-git module from current directory
Import-Module posh-git

# Load PSReadline module from current directory
Import-Module PSReadline
Set-PSReadLineOption -HistorySearchCursorMovesToEnd 
Set-PSReadlineKeyHandler -Key UpArrow -Function HistorySearchBackward
Set-PSReadlineKeyHandler -Key DownArrow -Function HistorySearchForward

# Load PSCX(PowerShell Community Extensions https://pscx.codeplex.com/) module
#Import-VisualStudioVars -VisualStudioVersion 2013 -Architecture x86
Import-VisualStudioVars -VisualStudioVersion 2010 -Architecture x86


Set-Alias vi  "C:/Program Files/Git/usr/bin/vim.exe"
Set-Alias vim "C:/Program Files/Git/usr/bin/vim.exe"

$desktop = "$HOME/Desktop"
$download = "$HOME/Downloads"
$myprofile = "$HOME/Documents/WindowsPowerShell/profile.ps1"

# PowerShell Prompt Set Begin

# Get full name of user
$UserName = [System.Environment]::UserName
$HostName = [System.Environment]::MachineName

# Am I an admin?
if ($Host.Version.Major -eq 5) # WMF 5.0
{
	$IsAdmin = [System.Security.Principal.WindowsPrincipal]::new([System.Security.Principal.WindowsIdentity]::GetCurrent()).IsInRole([System.Security.Principal.WindowsBuiltInRole]::Administrator)
} 
else # WMF 4.0
{
	$IsAdmin = [System.Security.Principal.WindowsPrincipal]::Current.IsInRole([System.Security.Principal.WindowsBuiltInRole]::Administrator)
}


# Function to write git repository status on prompt
function writegitprompt($status){
    if ($status) {
         Write-Host ' (' -NoNewline 
         Write-Host ($status.Branch) -NoNewline -ForegroundColor Cyan
         Write-Host ' ' -NoNewline 
         if($status.HasWorking) {
             Write-Host "$([char]0x25CF)" -NoNewline -ForegroundColor @{$true='Green';$false='DarkGray'}[$status.Working.Added -and $status.Working.Added.Count -ge 0]
             Write-Host "$([char]0x25CF)" -NoNewline -ForegroundColor @{$true=(@{$true='Red';$false='Yellow'}[$status.Working.Unmerged -and $status.Working.Unmerged.Count -ge 0]);$false=(@{$true='Red';$false='DarkGray'}[$status.Working.Unmerged -and $status.Working.Unmerged.Count -ge 0])}[$status.Working.Modified -and $status.Working.Modified.Count -ge 0]
             Write-Host "$([char]0x25CF)" -NoNewline -ForegroundColor @{$true='Red';$false='DarkGray'}[$status.Working.Deleted -and $status.Working.Deleted.Count -ge 0]
         } else {
             Write-Host "$([char]0x25CF)$([char]0x25CF)$([char]0x25CF)" -NoNewline -ForegroundColor DarkGray
         }
         if($status.HasIndex) {
             Write-Host "| " -NoNewline
             Write-Host "$([char]0x25CF)" -NoNewline -ForegroundColor @{$true='Green';$false='DarkGray'}[$status.Index.Added -and $status.Index.Added.Count -ge 0]
             Write-Host "$([char]0x25CF)" -NoNewline -ForegroundColor @{$true=(@{$true='Red';$false='Yellow'}[$status.Index.Unmerged -and $status.Index.Unmerged.Count -ge 0]);$false=(@{$true='Red';$false='DarkGray'}[$status.Working.Unmerged -and $status.Working.Unmerged.Count -ge 0])}[$status.Index.Modified -and $status.Index.Modified.Count -ge 0]
             Write-Host "$([char]0x25CF)" -NoNewline -ForegroundColor @{$true='Red';$false='DarkGray'}[$status.Index.Deleted -and $status.Index.Deleted.Count -ge 0]
         }
         Write-Host ')' -NoNewline		 
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
 # $stashCount = $null | git stash list 2>$null | measure-object | select -expand Count
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
            #GitDir          = $gitDir			
            Branch          = $branch
            #AheadBy         = $aheadBy
            #BehindBy        = $behindBy
            #Upstream        = $upstream
            HasIndex        = [bool]$index
            Index           = $index
            HasWorking      = [bool]$working
            Working         = $working
            #HasUntracked    = [bool]$filesAdded
            #StashCount      = $stashCount
        }
		
        return $result
    }
}


function MyWriteGitPrompt($gitDir = (Get-GitDirectory)) {
    $settings = $Global:GitPromptSettings
    $enabled = (-not $settings) -or $settings.EnablePromptStatus
	
    if ($enabled -and $gitDir)
    {		
        $branch = $null
        
        [bool]$indexAdded = $false
        [bool]$indexModified = $false
        [bool]$indexDeleted = $false
        [bool]$indexUnmerged = $false
        [bool]$HasIndex = $false

        [bool]$filesAdded = $false
        [bool]$filesModified = $false
        [bool]$filesDeleted = $false
        [bool]$filesUnmerged = $false
        [bool]$HasWorking = $false
	
		$status = git -c color.status=false status --short --branch 2>$null
		
        $status | foreach {
            
            if($_) {
                switch -regex ($_) {
                    '^(?<index>[^#])(?<working>.) (?<path1>.*?)(?: -> (?<path2>.*))?$' {
                        switch ($matches['index']) {
                            'A' { $HasIndex = $true; $indexAdded = $true }
                            'M' { $HasIndex = $true; $indexModified = $true }
                            'R' { $HasIndex = $true; $indexModified = $true }
                            'C' { $HasIndex = $true; $indexModified = $true }
                            'D' { $HasIndex = $true; $indexDeleted = $true }
                            'U' { $HasIndex = $true; $indexUnmerged = $true }                            
                        }
                        switch ($matches['working']) {
                            '?' { $HasWorking = $true; $filesAdded = $true }
                            'A' { $HasWorking = $true; $filesAdded = $true }
                            'M' { $HasWorking = $true; $filesModified = $true }
                            'D' { $HasWorking = $true; $filesDeleted = $true }
                            'U' { $HasWorking = $true; $filesUnmerged = $true }                           
                        }
                    }

                    '^## (?<branch>\S+?)(?:\.\.\.(?<upstream>\S+))?(?: \[(?:ahead (?<ahead>\d+))?(?:, )?(?:behind (?<behind>\d+))?\])?$' {
                        $branch = $matches['branch']
                    }

                    '^## Initial commit on (?<branch>\S+)$' {
                        $branch = $matches['branch']
                    }				
                }
            }
        }
		
		if (-Not $branch) {
			return
		}
		
        # Write Git Prompt
        Write-Host ' (' -NoNewline 
		$BranchColor = [System.ConsoleColor]::Cyan
        Write-Host ($branch) -NoNewline -ForegroundColor $BranchColor
        
        if ($HasIndex) {
			
			if ($filesAdded) {
				$GitAddedColor = [System.ConsoleColor]::Green
			} else {
				$GitAddedColor = [System.ConsoleColor]::DarkGray
			}
			if ($filesUnmerged) {
				$GitUnmergedColor = [System.ConsoleColor]::Red
			} elseif ($filesModified) {
				$GitUnmergedColor = [System.ConsoleColor]::Yellow
			} else {
				$GitUnmergedColor = [System.ConsoleColor]::DarkGray
			}
			if ($filesDeleted) {
				$GitDeletedColor = [System.ConsoleColor]::Red
			} else {
				$GitDeletedColor = [System.ConsoleColor]::DarkGray
			}
			Write-Host ' ' -NoNewline
			Write-Host "$([char]0x25CF)" -NoNewline -ForegroundColor $GitAddedColor
			Write-Host "$([char]0x25CF)" -NoNewline -ForegroundColor $GitUnmergedColor
			Write-Host "$([char]0x25CF)" -NoNewline -ForegroundColor $GitDeletedColor
		
            if ($indexAdded) {
                $GitAddedColor = [System.ConsoleColor]::Green
            } else {
                $GitAddedColor = [System.ConsoleColor]::DarkGray
            }
            if ($indexUnmerged) {
                $GitUnmergedColor = [System.ConsoleColor]::Red
            } elseif ($indexModified) {
                $GitUnmergedColor = [System.ConsoleColor]::Yellow
            } else {
                $GitUnmergedColor = [System.ConsoleColor]::DarkGray
            }
            if ($indexDeleted) {
                $GitDeletedColor = [System.ConsoleColor]::Red
            } else {
                $GitDeletedColor = [System.ConsoleColor]::DarkGray
            }
			Write-Host "| " -NoNewline -ForegroundColor $BranchColor
            Write-Host "$([char]0x25CF)" -NoNewline -ForegroundColor $GitAddedColor
            Write-Host "$([char]0x25CF)" -NoNewline -ForegroundColor $GitUnmergedColor
            Write-Host "$([char]0x25CF)" -NoNewline -ForegroundColor $GitDeletedColor
        } elseif ($HasWorking) {
			if ($filesAdded) {
				$GitAddedColor = [System.ConsoleColor]::Green
			} else {
				$GitAddedColor = [System.ConsoleColor]::DarkGray
			}
			if ($filesUnmerged) {
				$GitUnmergedColor = [System.ConsoleColor]::Red
			} elseif ($filesModified) {
				$GitUnmergedColor = [System.ConsoleColor]::Yellow
			} else {
				$GitUnmergedColor = [System.ConsoleColor]::DarkGray
			}
			if ($filesDeleted) {
				$GitDeletedColor = [System.ConsoleColor]::Red
			} else {
				$GitDeletedColor = [System.ConsoleColor]::DarkGray
			}
			Write-Host ' ' -NoNewline
			Write-Host "$([char]0x25CF)" -NoNewline -ForegroundColor $GitAddedColor
			Write-Host "$([char]0x25CF)" -NoNewline -ForegroundColor $GitUnmergedColor
			Write-Host "$([char]0x25CF)" -NoNewline -ForegroundColor $GitDeletedColor
		}	

        Write-Host ')' -NoNewline
    }
}


# Here we go
function global:prompt {
	$realLASTEXITCODE = $LASTEXITCODE
		
	if ($realLASTEXITCODE -eq 0) {
		$OmegaColor = [System.ConsoleColor]::Gray
	} else {
		$OmegaColor = [System.ConsoleColor]::Red
	}
	if 	($IsAdmin) {
		$UserColor = [System.ConsoleColor]::Red
	} else {
		$UserColor = [System.ConsoleColor]::Yellow
	}
	$PathColor = [System.ConsoleColor]::Green
	
	## write Johnny
	Write-Host $UserName -NoNewline -ForegroundColor $UserColor	
	## write  λ
    Write-Host " $([char]0x3C9) " -NoNewline -ForegroundColor $OmegaColor	
    ## write Path
	Write-Host(mypath__) -NoNewline -ForegroundColor $PathColor    
    # write Git Prompt
	# writegitprompt (MyGet-GitStatus)
	MyWriteGitPrompt
	## write  λ
    Write-Host " $([char]0x3BB)" -NoNewline -ForegroundColor $OmegaColor
    
    # Rightmost time display
    # Save cursor position first
    $saveY = [System.Console]::CursorTop
    $saveX = [System.Console]::CursorLeft
    $columns = (Get-Host).UI.RawUI.windowsize.width    # Column quantity of console window	
    [System.Console]::SetCursorPosition($columns - 10, $saveY)
    Write-Host "[" -NoNewline
    Write-Host (Get-Date -format "HH:mm") -NoNewline -ForegroundColor Cyan
    Write-Host "]" -NoNewline
    [System.Console]::SetCursorPosition($saveX, $saveY)        # Move cursor back

    $global:LASTEXITCODE = $realLASTEXITCODE
	#$global:LastPath = $pwd
    return " "
}

# PowerShell Prompt Set End

Pop-Location
Start-SshAgent -Quiet
