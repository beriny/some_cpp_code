$mypath = "$HOME/Desktop"

function getTickCount {
	$millisecondsUptime = [Environment]::TickCount
	"# Now $millisecondsUptime ms "
}

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
<#
 # Function to write git repository status on prompt
 # $status.Branch
 # $status.HasWorking
 # status.HasIndex
 # $status.Index
 #>
function writegitprompt($status){	
    if ($status) {
         write-host ' (' -nonewline 
         write-host ($status.Branch) -nonewline
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
<##>
echo ""
echo "========="
echo "workdir is $args"
echo ""

$status = MyGet-GitStatus $args


echo "========="
echo "MyGet-GitStatus: "
echo $status

echo "========="
echo "prompt: "
echo ""
writegitprompt ($status)

echo " "


<# MyGet-GitStatus 有意义的部分
 #
 # $status.HasWorking
 # $status.Branch 
 # $status.Index
 # $status.HasIndex 
 #
 #>
<#
#MyGet-GitStatus $args
MyGet-GitStatus $(Get-GitDirectory)
echo "########################"
Get-GitStatus $(Get-GitDirectory)
#>


