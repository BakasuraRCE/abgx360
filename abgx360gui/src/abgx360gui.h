//---------------------------------------------------------------------------
//
// Name:        abgx360gui.h
// Author:      Seacrest
// Created:     10/8/2007 9:06:46 PM
// Description: abgx360gui class declaration
//
//---------------------------------------------------------------------------

#ifndef __ABGX360GUI_h__
#define __ABGX360GUI_h__

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP

#include <wx/wx.h>
#include <wx/frame.h>

#else
#include <wx/wxprec.h>
#endif

//Do not add custom headers between
//Header Include Start and Header Include End.
//wxDev-C++ designer will remove them. Add custom headers after the block.
////Header Include Start
#include <wx/dirdlg.h>
#include <wx/filedlg.h>
#include <wx/menu.h>
#include <wx/config.h> // Needed For wxFileHistory
#include <wx/docview.h> // Needed For wxFileHistory
#include <wx/statusbr.h>
#include <wx/statbmp.h>
#include <wx/radiobut.h>
#include <wx/statbox.h>
#include <wx/stattext.h>
#include <wx/notebook.h>
#include <wx/bmpbuttn.h>
#include <wx/button.h>
#include <wx/textctrl.h>
#include <wx/checkbox.h>
#include <wx/choice.h>
#include <wx/sizer.h>
#include <wx/panel.h>
////Header Include End

#include <wx/tooltip.h>
#include <wx/utils.h>
#include <wx/aboutdlg.h>
#include <wx/choicdlg.h>
#include <wx/event.h>
//#include <wx/defs.h>
#include <wx/tipwin.h>
#include <wx/stopwatch.h>
#include <time.h>
#include <wx/dcbuffer.h>
#include <wx/dnd.h>  // drag and drop

#ifdef WIN32
#include <ddk/ntddstor.h>  // device i/o stuff
#endif

#ifdef __APPLE__
#include <CoreFoundation/CFBundle.h> // for OSX bundle-related stuff
#endif

////Dialog Style Start
#undef abgx360gui_STYLE
#define abgx360gui_STYLE wxCAPTION | wxSYSTEM_MENU | wxMINIMIZE_BOX | wxCLOSE_BOX
////Dialog Style End

#if wxUSE_DRAG_AND_DROP

class DnDInput : public wxFileDropTarget {
 public:
  DnDInput(wxTextCtrl *inputeditbox, wxChoice *inputselect, wxWindow *frame, int inputselectid) {
    dndeditbox = inputeditbox;
    dndselect = inputselect;
    dndframe = frame;
    dndselectid = inputselectid;
  }

  virtual bool OnDropFiles(wxCoord x, wxCoord y, const wxArrayString &filenames);

 private:
  wxTextCtrl *dndeditbox;
  wxChoice *dndselect;
  wxWindow *dndframe;
  int dndselectid;
};

#endif

class InfoTip : public wxPanel {
 private:
 DECLARE_EVENT_TABLE();

 public:
  //contructor
  InfoTip(wxWindow *parent, const wxBitmap &label, const wxString &infotext, const wxPoint &pos, const wxSize &size);

  void onMouseOver(wxMouseEvent &event);

  void onPaint(wxPaintEvent &event);

  wxTipWindow *tip;
  wxString mInfotext;
  wxBitmap mLabel;
  wxRect iconbounds;
};

class PrettyButton : public wxPanel {
 private:
 DECLARE_EVENT_TABLE();

 public:
  //contructor
  PrettyButton(wxWindow *parent, const wxBitmap &normalimage, const wxBitmap &mouseonimage, const wxBitmap &clickimage, const wxPoint &pos, const wxSize &size, int id);

  void onMouseEnter(wxMouseEvent &event);

  void onMouseLeave(wxMouseEvent &event);

  void onMouseClick(wxMouseEvent &event);

  void onMouseUp(wxMouseEvent &event);

  void onEraseBackground(wxEraseEvent &event);

  void onPaint(wxPaintEvent &event);

 private:
  bool click, hover;
  wxBitmap mNormalImage;
  wxBitmap mOverImage;
  wxBitmap mClickImage;
  wxWindow *mParent;
  wxCommandEvent *mEvent;
  wxStopWatch mSW;
};

class abgx360gui : public wxFrame {
 private:
 DECLARE_EVENT_TABLE();

 public:
  abgx360gui(wxWindow *parent,
             wxWindowID id = wxID_ANY,
             const wxString &title = wxEmptyString,
             const wxPoint &pos = wxDefaultPosition,
             const wxSize &size = wxSize(-1, -1),
             long style = wxDEFAULT_FRAME_STYLE | wxTAB_TRAVERSAL);

  virtual ~abgx360gui();

  void RunButtonClick(wxCommandEvent &event);

  void WxBitmapButton1Click(wxCommandEvent &event);

  void OpenButtonClick(wxCommandEvent &event);

  void SaveButtonClick(wxCommandEvent &event);

  void UIUpdate(wxUpdateUIEvent &event);

  void ProgramOutputSelected(wxCommandEvent &event);

  void PatchVideoOpenButtonClick(wxCommandEvent &event);

  void PatchPFIOpenButtonClick(wxCommandEvent &event);

  void PatchDMIOpenButtonClick(wxCommandEvent &event);

  void PatchSSOpenButtonClick(wxCommandEvent &event);

  void ExtractVideoSaveButtonClick(wxCommandEvent &event);

  void ExtractPFISaveButtonClick(wxCommandEvent &event);

  void ExtractDMISaveButtonClick(wxCommandEvent &event);

  void ExtractSSSaveButtonClick(wxCommandEvent &event);

  void MnuAboutClick(wxCommandEvent &event);

  void MnuSaveSettingsClick(wxCommandEvent &event);

  void MnuExitClick(wxCommandEvent &event);

  void MnuLoadSettingsClick(wxCommandEvent &event);

  void MnuClearHistoryClick(wxCommandEvent &event);

  void MnuFileHistoryClick(wxCommandEvent &event);

  void MnuDeleteSettingsClick(wxCommandEvent &event);

  void doLoadSettings();

  void MyRegionButtonClick(wxCommandEvent &event);

  void MatchOnlyButtonClick(wxCommandEvent &event);

  void InputChoiceSelected(wxCommandEvent &event);

  void MnuFolderHistoryClick(wxCommandEvent &event);

  void Mnuclearfilehistory1749Click(wxCommandEvent &event);

  void MnuClearDirHistoryClick(wxCommandEvent &event);

  void MnuDirHistoryClick(wxCommandEvent &event);
  void QuickstartChoiceSelected(wxCommandEvent &event);

  void abgx360_netClick(wxCommandEvent &event);

  void WhereStealthFilesClick(wxCommandEvent &event);

  void WhereImagesClick(wxCommandEvent &event);

 private:
  //Do not add custom control declarations between
  //GUI Control Declaration Start and GUI Control Declaration End.
  //wxDev-C++ will remove them. Add custom code after the block.
  ////GUI Control Declaration Start
  wxFileDialog *SaveSSFileDialog;
  wxFileDialog *SaveSSFileDialogClobber;
  wxFileDialog *SaveDMIFileDialogClobber;
  wxDirDialog *InputDirDialog;
  wxFileDialog *SaveTextFileDialog;
  wxFileDialog *SaveHTMLFileDialog;
  wxFileDialog *SavePFIFileDialog;
  wxFileDialog *OpenDMIFileDialog;
  wxFileDialog *SaveVideoFileDialogClobber;
  wxFileDialog *SaveDMIFileDialog;
  wxFileDialog *OpenPFIFileDialog;
  wxFileDialog *OpenSSFileDialog;
  wxFileDialog *SavePFIFileDialogClobber;
  wxFileDialog *OpenFileDialog;
  wxFileDialog *OpenVideoFileDialog;
  wxFileDialog *SaveVideoFileDialog;
  wxMenuBar *WxMenuBar1;
  wxFileHistory *m_fileHistory; // the most recently opened files
  wxConfig *m_fileConfig; // Used to save the file history (can be used for other data too)
  wxStatusBar *StatusBar;
  wxBitmapButton *SaveButtonDisabled;
  wxBitmapButton *dottedOpenButtonDisabled;
  wxStaticBitmap *TopBitmap;
  wxPanel *LaunchPanel;
  wxCheckBox *Maximize;
  wxCheckBox *TerminalFont;
  wxBitmapButton *SaveButton;
  wxTextCtrl *OutputFileEditBox;
  wxChoice *ProgramOutput;
  wxCheckBox *OpenFileWhenDone;
  wxStaticBoxSizer *OutputSizer;
  wxStaticText *PreferredLangText;
  wxChoice *PreferredLangChoice;
  wxCheckBox *EmbedImages;
  wxChoice *XexImages;
  wxChoice *SplitVid;
  wxStaticText *SplitVidText;
  wxStaticText *XexImagesText;
  wxTextCtrl *ExtraOptionsEditBox;
  wxButton *MyRegionButton;
  wxTextCtrl *MyRegionEditBox;
  wxStaticText *MyRegion;
  wxStaticText *WxStaticText10;
  wxPanel *WxNoteBookPage_Misc;
  wxCheckBox *KeepOriginalISO;
  wxRadioButton *NoRebuild;
  wxRadioButton *RebuildLowSpace;
  wxRadioButton *RebuildDefault;
  wxStaticText *WxStaticText9;
  wxPanel *WxNoteBookPage_Rebuilding;
  wxCheckBox *TrustSSv2;
  wxStaticText *WxStaticText5;
  wxChoice *FixBadAnglesValue;
  wxCheckBox *FixBadAngles;
  wxCheckBox *FixAngle359;
  wxCheckBox *FixDRT;
  wxStaticText *AutoFixText;
  wxChoice *AutoFix;
  wxPanel *WxNoteBookPage_AutoFix;
  wxCheckBox *Clobber;
  wxBitmapButton *ExtractSSSaveButton;
  wxTextCtrl *ExtractSSEditBox;
  wxCheckBox *ExtractSS;
  wxBitmapButton *ExtractDMISaveButton;
  wxTextCtrl *ExtractDMIEditBox;
  wxCheckBox *ExtractDMI;
  wxBitmapButton *ExtractPFISaveButton;
  wxTextCtrl *ExtractPFIEditBox;
  wxCheckBox *ExtractPFI;
  wxCheckBox *ExtractEntireVideoPartition;
  wxBitmapButton *ExtractVideoSaveButton;
  wxTextCtrl *ExtractVideoEditBox;
  wxCheckBox *ExtractVideo;
  wxStaticText *WxStaticText2;
  wxBitmapButton *PatchSSOpenButton;
  wxTextCtrl *PatchSSEditBox;
  wxCheckBox *PatchSS;
  wxBitmapButton *PatchDMIOpenButton;
  wxTextCtrl *PatchDMIEditBox;
  wxCheckBox *PatchDMI;
  wxBitmapButton *PatchPFIOpenButton;
  wxTextCtrl *PatchPFIEditBox;
  wxCheckBox *PatchPFI;
  wxBitmapButton *PatchVideoOpenButton;
  wxTextCtrl *PatchVideoEditBox;
  wxCheckBox *PatchVideo;
  wxCheckBox *PatchIfInvalid;
  wxCheckBox *PatchIfStealthPasses;
  wxCheckBox *CSVUpdate;
  wxChoice *Verbosity;
  wxStaticText *VerbosityText;
  wxCheckBox *ShowAvatarAwards;
  wxCheckBox *HideSecretAchievements;
  wxCheckBox *ShowAchievements;
  wxCheckBox *CheckGameCRCWhenNeeded;
  wxCheckBox *RecurseSubdirs;
  wxCheckBox *DisplayFilesystem;
  wxCheckBox *CheckVideoPadding;
  wxCheckBox *CheckStealth;
  wxCheckBox *StayOffline;
  wxCheckBox *UseColors;
  wxCheckBox *CheckCorruption;
  wxCheckBox *Verify;
  wxCheckBox *OnlineUpdate;
  wxCheckBox *CheckDVDFile;
  wxChoice *QuickstartChoice;
  wxTextCtrl *QuickstartMemo;
  wxNotebook *Notebook;
  wxBitmapButton *OpenButton;
  wxTextCtrl *InputFileEditBox;
  wxButton *MatchOnlyButton;
  wxTextCtrl *MatchOnlyEditBox;
  wxCheckBox *MatchOnly;
  wxCheckBox *WriteDisable;
  wxChoice *InputChoice;
  wxPanel *InputPanel;
  wxStaticBoxSizer *InputSizer;
  wxBoxSizer *MainSizer;
  ////GUI Control Declaration End
  wxFileHistory *m_folderHistory; // the most recently opened folders
  InfoTip *MyRegionTip, *RebuildDefaultTip, *RebuildLowSpaceTip, *AutoFixTip, *TrustSSv2Tip, *FixDRTTip, *FixAngle359Tip, *FixBadAnglesTip, *PatchIfStealthPassesTip, *CheckDVDFileTip,
      *CheckStealthTip, *VerifyTip, *CheckVideoPaddingTip, *CheckCorruptionTip, *CheckForUpdatesTip, *GameCRCTip, *SplitVidTip, *ImagesTip, *PreferredLangTip;
  PrettyButton *LaunchButton;
  wxStaticBitmap *Separator;
  int guifontpointsize;
#ifdef WIN32
  wxChoice *DriveChoice;
  wxArrayString arrayStringFor_DriveChoice;
#endif

 private:
  //Note: if you receive any error with these enum IDs, then you need to
  //change your old form code that are based on the #define control IDs.
  //#defines may replace a numeric value for the enum names.
  //Try copy and pasting the below block in your old form header files.
  enum {
    ////GUI Enum Control ID Start
    ID_MNU_FILE_1667 = 1667,
    ID_MNU_OPENINPUTFILE_1748 = 1748,
    ID_MNU_REOPEN_1745 = 1745,
    ID_MNU_CLEARHISTORY_1749 = 1749,
    ID_MNU_FILEHISTORY_1747 = 1747,
    ID_MNU_REOPENDIRECTORY_1772 = 1772,
    ID_MNU_CLEARDIRHISTORY_1773 = 1773,
    ID_MNU_LOADSETTINGS_1743 = 1743,
    ID_MNU_SAVESETTINGS_1668 = 1668,
    ID_MNU_DELETESETTINGS_1750 = 1750,
    ID_MNU_EXIT_1671 = 1671,
    ID_MNU_MAKEADONATION_1868 = 1868,
    ID_MNU_HELP_1669 = 1669,
    ID_MNU_GOTOABGX360_NET_1869 = 1869,
    ID_MNU_WHERE_STEALTHFILES_1872 = 1872,
    ID_MNU_WHERE_IMAGES_1875 = 1875,
    ID_MNU_ABOUT_1678 = 1678,

    ID_STATUSBAR = 1007,
    ID_SAVEBUTTONDISABLED = 1023,
    ID_DOTTEDOPENBUTTONDISABLED = 1729,
    ID_TOPBITMAP = 1721,
    ID_LAUNCHPANEL = 1838,
    ID_MAXIMIZE = 1847,
    ID_TERMINALFONT = 1846,
    ID_SAVEBUTTON = 1845,
    ID_OUTPUTFILEEDITBOX = 1844,
    ID_PROGRAMOUTPUT = 1843,
    ID_OPENFILEWHENDONE = 1841,
    ID_PREFERREDLANGTEXT = 1883,
    ID_PREFERREDLANGCHOICE = 1879,
    ID_EMBEDIMAGES = 1874,
    ID_XEXIMAGES = 1866,
    ID_SPLITVIDCHOICE = 1865,
    ID_SPLITVIDTEXT = 1864,
    ID_XEXIMAGESTEXT = 1863,
    ID_EXTRAOPTIONSEDITBOX = 1694,
    ID_MYREGIONBUTTON = 1755,
    ID_MYREGIONEDITBOX = 1754,
    ID_MYREGION = 1752,
    ID_WXSTATICTEXT10 = 1693,
    ID_WXNOTEBOOKPAGE_MISC = 1692,
    ID_KEEPORIGINALISO = 1691,
    ID_NOREBUILD = 1751,
    ID_REBUILDLOWSPACE = 1683,
    ID_REBUILDDEFAULT = 1685,
    ID_WXSTATICTEXT9 = 1681,
    ID_WXNOTEBOOKPAGE_REBUILDING = 1679,
    ID_TRUSTSSV2 = 1871,
    ID_WXSTATICTEXT5 = 1813,
    ID_FIXBADANGLESVALUE = 1812,
    ID_FIXBADANGLES = 1811,
    ID_FIXANGLE359 = 1805,
    ID_FIXDRT = 1804,
    ID_CRBOX = 1803,
    ID_AUTOFIXTEXT = 1802,
    ID_AUTOFIX = 1798,
    ID_WXNOTEBOOKPAGE_AUTOFIX = 1656,
    ID_CLOBBER = 1857,
    ID_EXTRACTSSSAVEBUTTON = 1739,
    ID_EXTRACTSSEDITBOX = 1634,
    ID_EXTRACTSS = 1633,
    ID_EXTRACTDMISAVEBUTTON = 1738,
    ID_EXTRACTDMIEDITBOX = 1637,
    ID_EXTRACTDMI = 1638,
    ID_EXTRACTPFISAVEBUTTON = 1737,
    ID_EXTRACTPFIEDITBOX = 1640,
    ID_EXTRACTPFI = 1639,
    ID_EXTRACTENTIREVIDEOPARTITION = 1642,
    ID_EXTRACTVIDEOSAVEBUTTON = 1736,
    ID_EXTRACTVIDEOEDITBOX = 1644,
    ID_EXTRACTVIDEO = 1643,
    ID_WXSTATICTEXT2 = 1624,
    ID_PATCHSSOPENBUTTON = 1727,
    ID_PATCHSSEDITBOX = 1625,
    ID_PATCHSS = 1623,
    ID_PATCHDMIOPENBUTTON = 1726,
    ID_PATCHDMIEDITBOX = 1626,
    ID_PATCHDMI = 1622,
    ID_PATCHPFIOPENBUTTON = 1725,
    ID_PATCHPFIEDITBOX = 1627,
    ID_PATCHPFI = 1621,
    ID_PATCHVIDEOOPENBUTTON = 1724,
    ID_PATCHVIDEOEDITBOX = 1628,
    ID_PATCHVIDEO = 1620,
    ID_PATCHIFINVALID = 1619,
    ID_PATCHIFSTEALTHPASSES = 1616,
    ID_WXNOTEBOOKPAGE_MANUALPATCHEXTRACT = 1089,
    ID_CSVUPDATE = 1877,
    ID_VERBOSITY = 1699,
    ID_VERBOSITYTEXT = 1741,
    ID_SHOWAVATARAWARDS = 1873,
    ID_HIDESECRETACHIEVEMENTS = 1862,
    ID_SHOWACHIEVEMENTS = 1861,
    ID_CHECKGAMECRCWHENNEEDED = 1860,
    ID_RECURSESUBDIRS = 1858,
    ID_DISPLAYFILESYSTEM = 1761,
    ID_CHECKVIDEOPADDING = 1760,
    ID_STEALTHCHECK = 1178,
    ID_STAYOFFLINE = 1179,
    ID_USECOLORS = 1180,
    ID_CHECKCORRUPTION = 1702,
    ID_VERIFY = 1170,
    ID_ONLINEUPDATE = 1169,
    ID_CHECKDVDFILE = 1168,
    ID_WXNOTEBOOKPAGE_OPTIONS = 1088,
    ID_QUICKSTARTCHOICE = 1828,
    ID_QUICKSTARTMEMO = 1827,
    ID_QUICKSTART = 1776,
    ID_NOTEBOOK = 1717,
    ID_OPENBUTTON = 1856,
    ID_INPUTFILEEDITBOX = 1855,
    ID_MATCHONLYBUTTON = 1854,
    ID_MATCHONLYEDITBOX = 1853,
    ID_MATCHONLY = 1852,
    ID_WRITEDISABLE = 1851,
    ID_INPUTCHOICE = 1850,
    ID_INPUTPANEL = 1849,
    ID_PANEL = 1001,
    ////GUI Enum Control ID End
    ID_DIR1 = 3001,
    ID_DIR2 = 3002,
    ID_DIR3 = 3003,
    ID_DIR4 = 3004,
    ID_DIR5 = 3005,
    ID_DIR6 = 3006,
    ID_DIR7 = 3007,
    ID_DIR8 = 3008,
    ID_DIR9 = 3009,
#ifdef WIN32
    ID_DRIVECHOICE = 3010,
#endif
    ID_RUNBUTTON = 3011
  };

 private:
  wxBitmap InfoTip_BITMAP;
  wxString openfilename, savefilename, cmd;
  void OnClose(wxCloseEvent &event);
  void assign_events();
  wxNotebook *generate_notebook(wxWindow *parent);
  wxPanel *generate_page_autofix(wxWindow *parent);
  wxPanel *generate_page_misc(wxWindow *parent);
  wxPanel *generate_page_manually_patch(wxWindow *parent);
  wxPanel *generate_page_options(wxWindow *parent);
  wxPanel *generate_page_quickstart(wxWindow *parent);
  wxPanel *generate_page_rebuilding(wxWindow *parent);
};

#endif //__ABGX360GUI_h__