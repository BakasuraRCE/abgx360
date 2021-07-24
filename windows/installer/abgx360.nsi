; abgx360.nsi
;
; Nullsoft Scriptable Install System
;
;--------------------------------

; set this if not defining version on cmd line i.e. /DVERSION=v1.0.0
; !define VERSION "v0.0.0"

!include "sections.nsh"
!include "LogicLib.nsh"

SetCompressor /SOLID lzma

CRCCheck on

ShowInstDetails show
ShowUninstDetails show

InstallColors 2020FF 000000

; The name of the installer
Name "abgx360 ${VERSION}"

; The file to write
OutFile "abgx360_${VERSION}_setup.exe"

; The default installation directory
InstallDir $PROGRAMFILES\abgx360

; Registry key to check for directory (so if you install again, it will 
; overwrite the old one automatically)
InstallDirRegKey HKLM "Software\abgx360" "Install_Dir"

;--------------------------------

; Pages

Page components
Page directory
Page instfiles

UninstPage uninstConfirm
UninstPage instfiles

;--------------------------------

; The stuff to install
Section "abgx360 (required)"

  SectionIn RO

  SetOutPath $SYSDIR
  File "abgx360.exe"

  ; In case the user has an old or unofficial version of abgx360 in the install folder,
  ; deleting this will make sure the gui launches the right exe
  Delete $INSTDIR\abgx360.exe

  CreateDirectory "$INSTDIR\StealthFiles"
  SetOutPath $INSTDIR\StealthFiles
  File /r StealthFiles\*.*

  ; Write the installation path into the registry
  WriteRegStr HKLM SOFTWARE\abgx360 "Install_Dir" "$INSTDIR"

  ; Write the uninstall keys for Windows
  WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\abgx360" "DisplayName" "abgx360 ${VERSION}"
  WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\abgx360" "UninstallString" '"$INSTDIR\uninstall.exe"'
  WriteRegDWORD HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\abgx360" "NoModify" 1
  WriteRegDWORD HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\abgx360" "NoRepair" 1

  WriteUninstaller $INSTDIR\uninstall.exe

SectionEnd


Section "abgx360 GUI" gui_id

  SetOutPath $INSTDIR
  File "abgx360gui.exe"

SectionEnd


Section "Start Menu Shortcuts"

  ; vista workaround: http://nsis.sourceforge.net/Shortcuts_removal_fails_on_Windows_Vista
  SetShellVarContext all

  CreateDirectory "$SMPROGRAMS\abgx360"
  CreateShortCut "$SMPROGRAMS\abgx360\Uninstall.lnk" "$INSTDIR\uninstall.exe" "" "$INSTDIR\uninstall.exe" 0

  ${If} ${SectionIsSelected} ${gui_id}
    CreateShortCut "$SMPROGRAMS\abgx360\abgx360 GUI.lnk" "$INSTDIR\abgx360gui.exe" "" "$INSTDIR\abgx360gui.exe" 0
  ${EndIf}
  
SectionEnd

;--------------------------------

; Uninstaller

Section "Uninstall"

  ; vista workaround
  SetShellVarContext all
  
  ; Remove registry keys
  DeleteRegKey HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\abgx360"
  DeleteRegKey HKLM SOFTWARE\abgx360

  ; Remove files and uninstaller
  Delete $SYSDIR\abgx360.exe
  Delete $INSTDIR\abgx360gui.exe
  Delete $INSTDIR\StealthFiles\*.*
  Delete $INSTDIR\uninstall.exe

  ; Remove shortcuts, if any
  Delete $SMPROGRAMS\abgx360\*.*

  ; Remove directories used
  RMDir "$SMPROGRAMS\abgx360"
  RMDir "$INSTDIR\StealthFiles"
  RMDir "$INSTDIR"

SectionEnd
