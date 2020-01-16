ReadME.txt

MTK USB Driver Installer is an application which can install the com port driver.

Please run InstallDriver.exe first, then plug in USB.
InstallDriver.exe will install these drivers for Windows 98SE/ME/2000/XP/Vista:
	Windows 98/ME/2000/XP/Vista: MTK62XX USB Com Port Driver
	Windows 98: Mass Storage Driver

File Description:
	1.2K_XP_COM Folder
		This folder including the inf which will be used in WinXP and Win2K.and the Logo certification file.
		usb2ser_2kXP.inf will be installed for Winxp/Win2K 32bit system.
		usb2ser_XP64.inf will be installed for Winxp/Win2K 64bit system.
		usb2ser_2kxp.cat is the LOGO certification file.
	2.98_Mass Folder
		This folder including the USB Mass storage driver for Win98/ME		
	3.98ME_COM Folder
		This folder including the Modem driver and CDC Driver		
	4.Vista_Win7 Folder
		This folder including the inf file which be used in Vista and Win7 system and the Logo certification file.
	5.InstallDriver.exe
		Exe file of the driver install.		
	6.installdrv64.exe
		this exe file will be called by InstallDriver.exe in 64bit environment,
		and Individual execution will not make any sense.

Notes:
1. "2K_XP_COM, Vista, 98_MASS, 98ME_COM" dirs and installer.dll must be put in the same direcotry of InstallDriver.exe
2. To run InstallDriver without GUI windows, use "InstallDriver -a".
3. Customers can customize usb2ser_XXX.inf file.
   There is a string in the file:
   MTK6218 = "USB Modem Driver" 
   You can modify it for your product name, for example:
   MTK6218 = "MY_PRODUCT Modem Driver" 
4. Win7 use the .inf file which under the Vista_Win7 Folder
5. Windows 2003 use the inf file which under the 2K_XP_COM

[v1.0812.0]
     [New Feature]
     1.Pass WHQL certification for Windows XP 32 bit

[v1.0821.0]
     [New Feature]
     1.Support Windows XP 64 bit 
 
[v1.0830.0]
     [Bug Fix]
      1.Remove the entry refering "V.42bis", since none of our modem supports this protocol

[v1.0845.0]
     [New Feature]
     1. Pass WHQL certification for Windows Vista 32 bit
     2. Pass WHQL certification for Windows Vista 64 bit

[v1.0945.0]
     [New Feature]
     1.Support Win 7 32 bit
     2.Support Win 7 64 bit
     3.Remove the Installer.dll
[v1.0948.0]
     [New Feature]
     1.Support Windows 2003  

 
