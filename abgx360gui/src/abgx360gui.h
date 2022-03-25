//---------------------------------------------------------------------------
//
// Name:        abgx360gui.h
// Author:      Seacrest
// Author:      2021 Bakasura <bakasura@protonmail.ch>
// Created:     10/8/2007 9:06:46 PM
// Description: abgx360gui class declaration
//
//---------------------------------------------------------------------------

#pragma once

// PRECOMPILED_HEADERS
// https://docs.wxwidgets.org/3.0/page_multiplatform.html
// For compilers that support precompilation, includes "wx.h".
#include <wx/wxprec.h>

#ifdef __BORLANDC__
#   pragma hdrstop
#endif

#ifndef WX_PRECOMP
// Include your minimal set of headers here, or wx.h
#   include <wx/wx.h>
#endif
// PRECOMPILED_HEADERS

#include <random>
#include <string>
#include <ctime>

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
#include <wx/mstream.h>

#include <wx/tooltip.h>
#include <wx/utils.h>
#include <wx/aboutdlg.h>
#include <wx/choicdlg.h>
#include <wx/event.h>
#include <wx/tipwin.h>
#include <wx/stopwatch.h>
#include <wx/dcbuffer.h>

#if defined(_WIN32) || defined(__CLION_IDE__)
  #include <ddk/ntddstor.h>  // device i/o stuff
#endif

#if defined(__APPLE__) || defined(__CLION_IDE__)
  #include <CoreFoundation/CFBundle.h> // for OSX bundle-related stuff
#endif

class InfoTip : public wxPanel {
 private:
 DECLARE_EVENT_TABLE();

 public:
  // constructor
  InfoTip(wxWindow *parent, const wxBitmap &label, const wxString &info_text, const wxPoint &pos, const wxSize &size);

  void onMouseOver(wxMouseEvent &event);

  void onPaint(wxPaintEvent &event);

  wxString m_info_text;
  wxBitmap mLabel;
  wxRect icon_bounds;
};

class abgx360gui : public wxFrame {
 private:
 DECLARE_EVENT_TABLE();
  const std::string name = "abgx360 Reloaded";
  const std::string title = this->name + " GUI";
  const std::string version = "2.0.0";
  const std::string website = "https://bakasurarce.github.io/abgx360/";

 public:
  abgx360gui(
	  wxWindow *parent,
	  wxWindowID id = wxID_ANY,
	  const wxString &title = wxEmptyString,
	  const wxPoint &pos = wxDefaultPosition,
	  const wxSize &size = wxSize(-1, -1),
	  long style = (wxDEFAULT_FRAME_STYLE & ~(wxRESIZE_BORDER | wxMAXIMIZE_BOX)) | wxTAB_TRAVERSAL
  );
  virtual ~abgx360gui();

  void RunButtonClick(wxCommandEvent &event);
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
  wxMenuBar *wx_menu_bar;
  wxFileHistory *m_fileHistory; // the most recently opened files
  wxConfig *m_fileConfig; // Used to save the file history (can be used for other data too)
  wxTextCtrl *StatusBar;
  wxBitmapButton *SaveButtonDisabled;
  wxBitmapButton *dottedOpenButtonDisabled;
  wxStaticBitmap *TopBitmap;
  wxPanel *LaunchPanel;
  wxCheckBox *Maximize;
  wxCheckBox *TerminalFont;
  wxBitmapButton *SaveButton;
  wxTextCtrl *OutputFileEditBox;
  wxChoice *ProgramOutput;
  wxChoice *Terminal;
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
  wxBitmapButton *LaunchButton;
#if defined(_WIN32) || defined(__CLION_IDE__)
  wxChoice *DriveChoice;
  wxArrayString arrayStringFor_DriveChoice;
#endif

 private:
  int ID_WX_MENU_REOPEN_FILES;
  int ID_WX_MENU_REOPEN_DIRECTORY;
  int ID_WX_MENU_LOAD_SETTINGS;
  int ID_WX_MENU_DELETE_SETTINGS;

  enum {
#if defined(_WIN32) || defined(__CLION_IDE__)
	ID_DRIVECHOICE,
#endif
	ID_SAVE_BUTTON_DISABLED,
	ID_DOTTED_OPEN_BUTTON_DISABLED,
	ID_LAUNCHPANEL,
	ID_DIR1,
	ID_DIR2,
	ID_DIR3,
	ID_DIR4,
	ID_DIR5,
	ID_DIR6,
	ID_DIR7,
	ID_DIR8,
	ID_DIR9
  };

 private:
  wxBitmap InfoTip_BITMAP;
  wxString open_filename, save_filename, cmd;
  void OnClose(wxCloseEvent &event);
  void assign_events();
  wxMenuItem *create_menu_item(wxMenu *menu_parent, const std::string &text, auto event_method);
  wxMenuItem *create_menu_item(wxMenu *menu_parent, const std::string &text, const std::string &help, auto event_method);
  wxMenuItem *create_menu_item(int itemid, wxMenu *menu_parent, const std::string &text, const std::string &help, auto event_method);
  wxNotebook *generate_notebook(wxWindow *parent);
  wxPanel *generate_page_autofix(wxWindow *parent);
  wxPanel *generate_page_misc(wxWindow *parent);
  wxPanel *generate_page_manually_patch(wxWindow *parent);
  wxPanel *generate_page_options(wxWindow *parent);
  wxPanel *generate_page_quickstart(wxWindow *parent);
  wxPanel *generate_page_rebuilding(wxWindow *parent);
};