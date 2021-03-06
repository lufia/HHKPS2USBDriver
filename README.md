# HHKPS2USBDriver

## Description

NAKANISHI IchiroさんのHHKPS2USBDriverを、
Yosemiteで使えるようにCodeSigningしたものです。

オリジナルのREADMEは[README.txt](/README.txt)にあります。

## Installation

releaseからHHKPS2USBDriver-(version).zipをダウンロード。
解凍して、kextファイルを **/Library/Extensions** にコピーします。

    $ ls -F
    HHKPS2USBDriver.kext/
	$ sudo cp -R HHKPS2USBDriver.kext /Library/Extensions/

その後、PS2toUSB Converterを抜き差しすればExtensionがロードされます。

## Bugs

### キーボードが見つからない

*ioclasscount* で `0` と出力される場合、

    $ ioclasscount HHKPS2USBDriver
    HHKPS2USBDriver = 0

この場合、Info.plistにPS2toUSB ConverterのVendorID, ProductIDが登録されていません。

    $ ioreg -l

からPS2toUSBのようなデバイスを探すか、
このMacについて→システムレポート→ハードウェア→USBから、PS2toUSBデバイスを探して、
製造元ID(idVendor)と製品ID(idProduct)を、Info.plistに追加ください。
システムレポートの場合は16進数表記になっているため、10進数に変換してから使います。

### ドライバがロードできない

*ioclasscount* で `<no such class>` と出力される場合、

    $ ioclasscount HHKPS2USBDriver
	HHKPS2USBDriver = <no such class>

この場合、Extensionがロードされていません。

    $ cd /Library/Extensions
    $ codesign --verify -dvvv HHKPS2USBDriver.kext
    $ codesign --verify -vvvv HHKPS2USBDriver.kext
    $ spctl -a -vvvv HHKPS2USBDriver.kext
    $ kextutil -t HHKPS2USBDriver.kext

このあたりでコード署名が正しいか確認できます。
