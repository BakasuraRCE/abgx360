Title: Old News
Date: 2022-02-17
Modified: 2022-02-17
Summary: Old news from the original author Seacrest

The following news are copied from the original website of author Seacrest

[TOC]

## 2018-08-09

Sorry for the downtime over the past couple of weeks, but the site has now been moved to a new server. Our many thanks to our friends at [Team-Xecuter](https://web.archive.org/web/20180731051709/https://team-xecuter.com/){:target="_blank"} for graciously
providing the bandwidth from now on!

However, our original first domain <u>abgx360.net</u> has been completely different site for a few years now. As such to get the abgx360 app working again you will need to download
this [abgx360.ini]({static}/static/files/old-news/abgx360.ini.zip){:target="_blank"} file and extract it from the zip archive to the folder directly above your StealthFiles folder. To find out where your
StealthFiles folder is, open abgx360 GUI v1.0.6 and press Ctrl+F (and click yes to have it opened for you). Then go one folder up to where you see the abgx360.dat file and put that abgx360.ini file
you extracted in there right next to it.

From now on our domain and site is located at <u>https://abgx360.xecuter.com</u> with an special reverse proxy now working at <u>http://abgx360.cc</u> for the outdated GUI itself, since it can not corrently handle
today's era of always-secure connections.

Our many thanks for all your valuable user feedback on the TX Forums recently and your stay calm patience in getting us back up and running again with the first changes in over 4 years.

-- TEAM-XECUTER Is Still Rocking The Xbox Scene In 2018 And Beyond! --

## 2012-01-03

abgx360 v1.0.6 released!

Changes affecting all platforms:

- XGD3 support.
- Replaced AP25 replay sector support with support for topology data (for consoles which do AP25 checks -- make sure you have LT+ v3.0 or later).
- Added "Min Kernel Required" (to boot the game) when checking an XEX.
- Added improvements to AutoUpload (used by uploaders) including extended C/R for SS (using the original disc) to make sure files uploaded to the database have very accurate angle measurements.
- Added optional command line argument "--speed" for setting drive speed when checking a burned DVD. Example: "--speed 12" will attempt to set the drive speed to 12x. You can try to set any speed you
  like, but setting a speed higher than what your media supports may cause read errors if the drive's firmware doesn't govern it. "--speed 0" will set the drive's default speed.
- Added optional command line argument "--showsstable" for when you want to see the SS C/R data but you still prefer medium or low verbosity. The SS C/R table has also been updated with "Mod?" being
  split into "Tol" (response tolerance) for the CCRT entry and "Mod" (response modifier) for the drive entry, also "Pad?" has been renamed to "Typ" (type). Thanks Redline99!- Added vendor specific
  additional info and bus type when displaying optical drive names (bus type displayed on Windows only).
- Updated the list of optical drive sense code errors.
- Updated the game ratings definitions.
- Fixed a bug which negated the ability to recover from a write error when rebuilding an ISO using the low disk space method. It's unlikely that a write error would be recovered on subsequent retries,
  but at least now it will write the data in the correct place if it does recover.
- Fixed a bug which caused "Unknown Media: 0x00000000" to be displayed if the "Secure Virtual Optical Device" media flag was set and the "XGD2 Media Only" image flag was not set (The "XGD2 Media Only"
  flag has also been renamed to "Original Media Only" in abgx360 since they are using the same flag for XGD3).
- The archaic caution message about angle 359 was removed, but you are still able to "fix" it if you still have iXtreme < v1.4 (really old and not suitable for XBL anyway).
- Ability to "extract entire video partition (253 MB)" was removed; this doesn't make sense for XGD3 and isn't even very useful for XGD2 since it was just including a bunch of padding data that isn't
  even part of the real video partition... it was only needed for very old methods of concatenating with stealth files and a game partition to make a working backup.

Note: The way video is checked/fixed is now a little different for both XGD2 and XGD3. The previous way was to check/fix both L0 video and L1 video off of L0, and then to check/fix "SplitVid" (L1
video on L1) afterwards by comparing it to L1 video on L0. Since XGD3 has no room for L1 video on L0, and to keep things consistent, video will now always be checked/fixed according to L0 on L0 and L1
on L1, and the "SplitVid" check is now gone (nominally). The only effective difference is that L1 video on L0 is no longer checked, but this is not a problem... it's not even supposed to be there and
it's not visible to the host console when using a "safe" custom firmware. You can rest assured that only old and unsafe custom firmwares will read L1 video from L0; newer ones will read it properly
from L1 (this is necessary in order to replicate the read/seek performance of an original disc).

There is also a big annoying yellow message if you have "Check/Fix Video padding" enabled and you check an XGD2 game with L1 video on L0 (or any data in that area). To make the message go away you
will need to either add command line option "--pL0" to confirm that you want to blank it out (XGD2 ISOs without L1 video on L0 will appear to have bad video data when checked with older versions of
abgx360), or you can simply disable "Check/Fix Video padding", as it still makes no difference in terms of stealth... this option only exists as a way to make sure ISOs are "clean", with no extra data
in areas that aren't CRC checked. Note that this version of abgx360 doesn't care about L1 video on L0... it will pad L0 video with zeroes whenever video is autofixed or manually patched.

Sorry if the command line options are annoying (you can add them under the "Misc" tab of the GUI), but you can be sure that an improved v1.1.0 GUI is in the works...

<span class="text-yellow">Note: The GUI has not been changed and will still display version 1.0.2, don't worry about it as long as the CLI app displays v1.0.6</span>

## 2011-08-05 (Updated 2011-11-17)

<u>**Note: This information is obsolete as of the release of iXtreme LT+ v3.0 and the new method of using topology data.**</u>

Important note that bears repeating about iXtreme LT+ v1.91 (and this probably applies to any subsequent firmware as long as additional random AP25 challenges [nicknamed "AP26"] are being used):

"Due to the new AP26 random challenges the safety freeze for unknown or bad AP25 data is no longer supported. Please ensure your AP25 data is correct for the dashboard version you are using."

This means that (for consoles which do AP25 checks [see the [AP25 FAQ](https://web.archive.org/web/20130227090446/http://forums.xbox-scene.com/index.php?showtopic=728912){:target="_blank"} for info]):

1. AP25 backups (see the [list of AP25 games]({static}/static/files/old-news/ap25-games-list.html){:target="_blank"}) that are not patched with AP25 replay data will fail the normal AP25 challenges outright. (The normal AP25 challenges from the
   DAE table are still being performed along with the new random "AP26" challenges.)
2. AP25 backups that are patched with old/incomplete/bogus AP25 replay data will fail the normal AP25 challenges outright.
3. **AP25 backups that are patched with current AP25 replay data will fail the normal AP25 challenges outright when the DAE table is updated again.** So far the DAE table has only been updated through
   system (dashboard) updates but it *could* possibly be updated by other means.

Any of these failures will probably flag your console for a ban in the next banwave. As always you should be very wary of system updates and carefully follow the news here as well as
on [c4evaspeaks.com](https://web.archive.org/web/20110805115112/http://c4evaspeaks.com/){:target="_blank"}, [team-xecuter.com](https://web.archive.org/web/20110830140941/http://team-xecuter.com/){:target="_blank"} and [xbox-scene.com](https://web.archive.org/web/20110808001638/http://xbox-scene.com/){:target="_blank"}.

**Update 2011-11-16:**

DAE.bin is being silently updated through Xbox Live with an additional challenge table! This happens on the current public dashboard version 2.0.13604.0 and there is no confirmation dialog or any
known means to prevent it besides disconnecting your console from the internet.

If your DAE.bin has already been silently updated, **AP25 backups that are patched with current AP25 replay data will fail the normal AP25 challenges outright!** Note that all XGD3 games use AP25.

Use your originals if you want to play on Xbox Live.

**Update 2011-11-17:**

The Fall 2011 preview dashboard version 2.0.14692.0 is now rolling out. If you are in the preview and accept the update, it will now actively use the additional DAE challenge table and **AP25 backups
that are patched with current AP25 replay data will fail the normal AP25 challenges outright!**

## 2011-06-16

All AP25 replay data in the database has been updated as of 2011-06-14. See Defosho's [AP25 games list]({static}/static/files/old-news/ap25-games-list.html){:target="_blank"} and [AP25 FAQ](https://web.archive.org/web/20130227090446/http://forums.xbox-scene.com/index.php?showtopic=728912){:target="_blank"} for details. Note that this replay
data is meant for dashboard version 2.0.13146.0 and will not work if you haven't updated. For information and recommendations about the update,
read [Defosho's System Update FAQ](https://web.archive.org/web/20111007022805/http://forums.xbox-scene.com/index.php?showtopic=730311){:target="_blank"} and <u>stefanou's FAQ</u> [1]({static}/static/files/old-news/FAQ1.pdf){:target="_blank"} [2]({static}/static/files/old-news/FAQ2.pdf){:target="_blank"} [3]({static}/static/files/old-news/iXtreme_Burner_Max_Tutorial.pdf){:target="_blank"}.

## 2010-12-06

abgx360 v1.0.5 released!

Changes affecting all platforms:

- Fixed a bug when AutoFixing or manually patching Video that would cause an AP25 replay sector to get blanked out (some functions were still using the old hardcoded value for Video padding size)-
  Improved Game CRC progress indicator to prevent poor formatting if "Time Left" became more than 999 minutes- Added progress indicators for Video CRC, SplitVid and SplitVid padding checks- Now using
  bigbuffer when checking SplitVid which results in much faster performance when comparing L1 Video on L0 to L1 Video on L1 (especially when checking a burned DVD)

Note: The GUI has not been changed and will still display version 1.0.2, don't worry about it as long as the CLI app displays v1.0.5

## 2010-11-23

abgx360 v1.0.4 released!

Changes affecting all platforms:

- AntiPiracy 2.5 (AP25) replay sector for iXtreme LT+ firmware is checked for when a game has the AP25 system flag in the Xex set or when its media ID matches a list updatable through abgx360.dat (
  Fable III is the only game so far that uses AP25 but does not have the AP25 system flag set)
- AP25 replay data is Verified/AutoFixed according to your settings, albeit separately from the normal INI based Verify/AutoFix, so make sure to read the entire abgx360 output
- Video padding size changed to support the new AP25 replay sector using a variable which is updatable through abgx360.dat in case additional stealth sectors are needed so that the video padding check
  will not blank them out
- Removed short explanations of ISO filesizes (unnecessary, hard to keep updated and misleading in terms of SplitVid; just because an ISO has the space for SplitVid doesn't mean it has valid SplitVid
  data in that space)
- gzip compression is now supported when abgx360 downloads certain files
- miscellaneous small changes

Note: The GUI has not been changed and will still display version 1.0.2, don't worry about it as long as the CLI app displays v1.0.4

## 2010-11-06

abgx360 v1.0.3 released!

Changes affecting all platforms:

- Added full support for all current PFI/Video waves and the ability for future waves to be fully supported through updates to abgx360.dat
- The SplitVid check is now mandatory when checking an ISO/DVD and the "Check Stealth" option is enabled (iXtreme LT requires SplitVid for XBL safety)

Note: The GUI has not been changed and will still display version 1.0.2, don't worry about it as long as the CLI app displays v1.0.3

Sorry for the long release interval but v1.1.0 is taking much longer than expected and hopefully this interim update will address the main concern people were having, even though v1.0.2 was designed
to support new PFI/Video waves as long as the game was verified, v1.0.3 gets rid of the yellow text and also allows you to check SplitVid on newer games that haven't been verified yet. It does not,
however, add automatic searching/patching of SS v2 files. That's something that isn't even finished in v1.1.0 yet, and there's still the matter of SS v3 to deal with.

Note 2: XBL safety is very uncertain at the moment... The latest LT firmware for Samsung drives is considered by many to be fairly safe (since the TS-H943A ms25/ms28 original firmware doesn't support
AP 2.5) but owners of other drives need to be very careful and upgrade to LT+ when it becomes available.

Note 3: Just because the source code for abgx360 is made available, it does not imply a right to make changes and/or distribute source or binaries. Permission to do so is granted on a case-by-case
basis. This is necessary to prevent people from distributing buggy code or binaries which may adversely affect the online database, or distributing potentially virus infected binaries on sites that
appear official but are not. If you only need to make a small change to enable compilation on your system, permission is hereby granted to do so, as long as it does not affect the way abgx360
communicates with its online database in any way.

## 2009-11-11

abgx360 v1.0.2 released!

Changes affecting all platforms:

- Added support for 4th Wave PFI/Video
- Added support for SS v2
- Added the new check for DMI corruption which the database has been using since 2009-06-14
- Added ability to at least try to verify the game data when no Xex/SS ini is available and we're not going to AutoFix
- Added support for Avatar Awards
- Added option to select your preferred language to use when displaying strings from the Xex title resource
- Added drag & drop support for the GUI Input panel
- Added option to embed images in the HTML source code as data URIs for better portability (when using HTML output)
- Added JavaScript to HTML output that allows you to check off achievements and see the achieved text (especially useful when the how-to text is vague)
- Added a Donate button to the GUI so you can help me pay the bills and continue working on improvements :)
- Removed "Look for verified files in the local folder only" option from the GUI. I can't tell you how many people have checked this box without reading it because they saw it in a tutorial or someone
  else told them to do it, and then they can't figure out why abgx360 says you need to enable online functions. Please stop writing/following tutorials! Just read the Quickstart topics, the tutorial
  is right there.
- Checking for updates to GameNameLookup.csv is now optional (the csv was eating 50% of our bandwidth and you probably don't need it anyway since the game name can be retrieved directly from the Xex)
- Fixed a bug where folders would be considered files when parsing the ISO filesystem on some recent games
- Fixed a bug where default.pe (a temporary file used when decompressing a compressed default.xex) wasn't being deleted automatically
- Fixed a bug where unicode code point 160 (no-break space) would be displayed in a CLI window as " ?" instead of " "
- Small changes to the way some messages are displayed (harder to miss)

Changes affecting Windows:

- Now storing data files in the AppData folder to prevent errors related to permissions and UAC. You can open the GUI and hit Ctrl+F to find out where your StealthFiles are now stored and optionally
  have it opened for you. abgx360 will still check for Video ISOs in the old install directory first though, so you don't need to move that 3rd Wave Video ISO if you have it saved there already.
- Using libcurl 7.19.6 which should hopefully fix some strange connection problems affecting a small percentage of users

Changes affecting Linux/BSD:

- Fixed a bug on 64 bit systems which made it impossible to read PFI/Video exceptions from abgx360.dat
- Added code to the unix version of kbhit() to prevent hanging when abgx360 is launched as a background process

Changes affecting Mac OS X:

- Fixed a bug where abgx360 would fail to launch if you supplied a filename that contained an apostrophe
- Changed the dark gray text used for things like achievement type to normal gray since it was actually showing up black (invisible on a black background)
- Removed GUI option to "Use Terminal font characters" (this refers to a Windows font which replicates CP437 characters and not Terminal.app)

Special Note: It's recommended to wait for iXtreme LT (Lite Touch) before you play any more backups or originals on an unbanned console flashed with custom firmware.

## 2009-10-16

Looks like we were wrong in assuming that iXtreme v1.51 was fully compatible with 4th Wave PFI/Video. Turns out that only Hitachi iXtreme v1.51 will boot 4th Wave backups, and BenQ/LiteOn/Samsung
iXtreme v1.51 will NOT boot 4th Wave. It would have been fully compatible if only the Video data had changed but not with the change in PFI (capacity). So currently the only safe option for booting
4th Wave backups on a BenQ/LiteOn/Samsung drive is to use iXtreme v1.6 and the one shot boot disc.

## 2009-10-15 <span class="text-yellow">(Updated 2009-10-16)</span>

==============================<br>
Wave 4 and YOU v1.2 by Kushan<br>
==============================

A n00b's guide to everything Wave4

================<br>
What IS "Wave 4"?<br>
================

A regular, retail Xbox 360 disk is split into several sections or "partitions". One of these partitions is known as the "video partition". Before March 2009, this partition simply contained a video
that would play if you inserted the disk into a regular DVD player, the video would basically tell you that you were an idiot and need to put it into an Xbox 360 to play it.

One of the ways Microsoft can detect you being a dirty, filthy pirate is to scan this video to make sure it matches with what is supposed to be on the disk, so to protect you, the firmware itself does
a quick checksum of it and if it doesn't match with known video data, it wont boot. Every now and then, this video changed, with each change being called a "wave".

Normally, system updates (dashboard updates) are stored on a different part of the disk, taking up about 8Mb of space, however in November 2008 Microsoft launched the "NXE", a completely new Dashboard
for the system. Along with the new dash came Avatars, making the whole update substantially larger (somewhere in the region of 130MB). This meant the update wouldn't fit on the disk in the same
partition that previous updates were located and so instead the update was placed within the video partition. This was known as "wave 3" and hit around March 2009.

As Microsoft now distributes new Dashboard updates in the same partition, each time the 360 gets a software update, we will see a new "wave" a few months later. There was a Dashboard update in August
2009 and that is now being distributed with the latest games. This is known as Wave4. Its identical to Wave3, except the video partition now contains the August 09 Dash update. The first known game to
have this was Cars Race-o-rama.

Now, its important to remember that iXtreme was designed to PROTECT you and part of that protection is the "video partition" check. When this video partition changes, the firmware doesn't know if its
just a new "wave" or if its a bad rip and thus opts to not boot it.

When wave 3 hit, iXtreme 1.51 was quickly released to tackle the problem. This was a temporary fix only, the firmware simply does not do the video partition check and thus <s>boots</s> <span class="text-yellow">was supposed to
boot</span> ANY wave, up to wave 4 and beyond.

However, this in itself is "unsafe". If the disk is fine, then you'll be fine, but if the video partition is in any way corrupt, iXtreme 1.51 will still boot it and thus you could be detected by
Microsoft and banned. This also is not helped by the fact that some impatient, idiotic people decided to "patch" Wave3 games with Wave2 data in order to get iXtreme 1.5 or below to boot it. This is a
great way to get yourself banned and thus iXtreme 1.6 was created.

ix1.6 will only boot games that have the CORRECT video partition, up to and including wave 3. This means that if you have a Wave 3 game that was patched with a Wave 2 video partition (aka a great big
bullseye for Microsoft to target), iXtreme 1.6 will not boot it but ix1.51 will.

================<br>
Will I need a new firmware to play Wave 4 games?<br>
================

IF you are on iXtreme 1.5 or below, Wave3 games will not boot for you and thus Wave4 games will not either. In this case, YES you need to update your firmware!

IF you are on iXtreme 1.51 <span class="text-yellow">(Hitachi)</span>, then ANY wave will boot fine, including Wave4 however you must be EXTRA careful as you are not protected against corrupt or incorrect video partitions. This is
one of the many reasons to always use abgx360. If a game is fully verified, playing it on iXtreme 1.51 is just as safe as playing it on iXtreme 1.6 - this includes Wave4 games.

<span class="text-yellow">IF you are on iXtreme 1.51 (BenQ/LiteOn/Samsung), then YES you need to update your firmware!</span>

IF you are on iXtreme 1.6, you can ALSO play Wave 4 and above games, however you need to use a special activation disk to do so. This was added to the firmware specifically for this eventuality - the
disk activates "one-shot-boot" mode, essentially it allows iX1.6 to boot any game you insert into the drive, even if its not properly stealthed. You simply insert the disk into the drive, let it spin
up (it will say "play DVD"), then swap in your Wave4 game. You will need to do this each time you want to play a Wave 4 (or above) game. Don't worry, if the game has all the necessary stealth data,
then iX1.6 will still use it, so if you boot a VERIFIED Wave4 game using this method, you should be just as safe as you were booting a verified wave 3 game.

The disk is available here: [http://www.mediafire.com/?0njymu2bmio]({static}/static/files/old-news/activate.rar){:target="_blank"} and needs to be burned to a DUAL LAYER disk, but entirely on the first layer (do not set a layerbreak and when imgburn prompts, tell
it to burn to the first layer only).

A new iXtreme firmware will eventually be released with strict wave4 support (no activation disk needed), however some time needs to pass before this happens. Although Cars: Race-o-Rama was the first
game to appear in the wild with Wave 4 video, it was not necessarily the first game to be pressed with it. Also, during a wave transition there are often a few exceptions to the process which also
need to be known about. There will be no timeframe for this, so do not ask.

================<br>
What about abgx360? Will that need to be updated?<br>
================

abgx360 v1.0.1 (latest as of time of writing) does not recognise a "wave 4" image and will report a POSSIBLE corrupt/bad PFI/Video partition, however the program is actually still completely
compatible with Wave 4 games. Once a Wave4 title is verified, abgx360 will still download the .ini from the database and fully check out the image. If the image matches and the game is verified, then
it has also passed the stealth checks and thus it is as safe to play as any wave3 or wave2 game.

abgx360 v1.0.2 will be released with full Wave4 recognition in a similar manner to the new iXtreme; that is once the transition date is known and any exceptions are noted.

## 2009-08-08

OpenKey v0.2 released!

- Added an additional file validity check for matching barcode data in both inquiry and serial areas- Added automatic .bin.key creation (prompts for overwrite confirmation if the file already exists)-
  Added pretty hex display :)

[Download it here]({static}/static/files/old-news/openkey_v0.2.rar){:target="_blank"}

## 2009-08-07

OpenKey v0.1 released!

I just wanted to get a look at the super advanced crypto that goes into 83850c but apparently Geremia is not sharing source code for FreeKey... so one thing led to another and i ended up writing this
little app while deciphering the (actually quite disappointing) algorithm. Enjoy!

This is mainly provided for curious people and I can NOT guarantee that the keys it gives you are correct (but it seems to work properly). Please don't ask me for help with this application unless you
are working on integrating this functionality into JungleFlasher :)

[Download it here]({static}/static/files/old-news/openkey_v0.1.rar){:target="_blank"}

Love, Seacrest

## 2009-06-14

Note: If you have recently AutoFixed "UFC 2009 Undisputed", "Red Faction: Guerilla" or "Up" using abgx360, it may have patched a corrupt DMI to your ISO.

How can you tell if your ISO or Burned DVD has the bad DMI? Simply check the game with abgx360 on medium or high verbosity and look for "DMI CRC = XXXXXXXX".

For "UFC 2009 Undisputed" the corrupt DMI CRC = 46C162C8For "Red Faction: Guerilla" the corrupt DMI CRC = 580B3E16For "Up" the corrupt DMI CRC = F9F50C0F

How do you fix it if you have the corrupt DMI? If you already burned the game and deleted the ISO you will have to copy the disc back to your HDD (ImgBurn is recommended for Windows users). Also make
sure that you have online functions enabled in abgx360 for the next steps.

For "UFC 2009 Undisputed" simply check the ISO with AutoFix threshold set to level 3 and it will automatically download the updated ini and patch a good DMI for you. For "Red Faction: Guerilla" you
will need to delete 1A5575DDA1D2466C.ini (if it exists) from your StealthFiles folder and then check the ISO with AutoFix set to level 3. For "Up" you will need to delete E4F12417A1CB7F98.ini and
Xex_A1CB7F98.ini (if they exist) from your StealthFiles folder, however there is currently no other verified rip of this game in the database so you will have to wait on that.

Where is your StealthFiles folder?

On Windows this is usually C:\Program Files\abgx360\StealthFiles\On other systems this is usually ~/.abgx360/StealthFiles/

We apologize for this but this is a new type of corruption which seems to be associated with ripping via a certain USB->SATA adapter (not 100% sure of the cause yet) and DMI is now scanned for this
corruption before being accepted into the database (so it won't happen again).

Update: For users running Windows Vista / Windows 7 with UAC enabled, you may also need to delete these files from your VirtualStore folder. It will be something like C:\Users\<username>
\AppData\Local\VirtualStore\Program Files\abgx360\StealthFiles

## 2009-03-23

abgx360 v1.0.1 released!

Changes affecting all platforms:

- Added PFI/Video exceptions for "Disney Sing It: High School Musical 3 - Senior Year" and "Monsters vs. Aliens"
- Added support for new PFI/Video exceptions to be quickly added (and existing ones removed if necessary) via updates to abgx360.dat
- Fixed a bug which caused a blank or incomplete .dvd file to be considered valid
- GUI font size is now adjusted at runtime to prevent cut off text on some systems

Changes affecting Linux/BSD:

- Fixed a bug on 64 bit systems which made it impossible to add SplitVid
- GUI "Maximize it" option now works with latest xterm
- Numerous small changes to eliminate errors and warnings on latest gcc/g++

## 2009-03-13

"Disney Sing It: High School Musical 3 - Senior Year" is now the earliest known game to have 3rd wave PFI/Video. The current abgx360 v1.0.0 doesn't know this and will wrongly attempt to AutoFix it
with 2nd wave PFI/Video. Playing this game with 2nd wave PFI/Video is NOT safe for XBL, no matter what v1.0.0 says.

Stay tuned for an update to fix this issue.

## 2009-03-07

abgx360 v1.0.0 is finally here to save you from the BAN HAMMER!

Very easy to use. Runs natively on practically any operating system. All the info you could want is contained in the GUI. If you still need a tutorial or you plan to write one, you're an idiot.

Enjoy and thanks to everyone involved! You know who you are!

Love, Seacrest