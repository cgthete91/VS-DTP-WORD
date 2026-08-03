Code snippet

[Setup]
AppName=VS DTP WORD
AppVersion=1.0
DefaultDirName={autopf}\VS DTP WORD
DefaultGroupName=VS DTP WORD
OutputBaseFilename=VS_DTP_WORD_Setup_x64
Compression=lzma2
SolidCompression=yes
ArchitecturesAllowed=x64
ArchitecturesInstallIn64BitMode=x64

[Files]
Source: "..\build\Release\*"; DestDir: "{app}"; Flags: ignoreversion recursesubdirs

[Icons]
Name: "{autoprograms}\VS DTP WORD"; Filename: "{app}\VSDTPWord.exe"
Name: "{autodesktop}\VS DTP WORD"; Filename: "{app}\VSDTPWord.exe"

[Run]
Filename: "{app}\VSDTPWord.exe"; Description: "Launch VS DTP WORD"; Flags: postinsta
