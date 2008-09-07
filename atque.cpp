// -*- C++ -*- generated by wxGlade 0.6.3 on Sat Sep  6 18:07:53 2008

#include "atque.h"
#include "split.h"
#include "merge.h"
#include <iostream>

#include <wx/filename.h>

// begin wxGlade: ::extracode
// end wxGlade

AtqueWindow::AtqueWindow(wxWindow* parent, int id, const wxString& title, const wxPoint& pos, const wxSize& size, long style):
    wxFrame(parent, id, title, pos, size, wxICONIZE|wxMINIMIZE|wxCLOSE_BOX|wxSYSTEM_MENU)
{
    // begin wxGlade: AtqueWindow::AtqueWindow
    menuBar = new wxMenuBar();
    wxMenu* fileMenu = new wxMenu();
    fileMenu->Append(wxID_ABOUT, wxT("About Atque..."), wxEmptyString, wxITEM_NORMAL);
    fileMenu->AppendSeparator();
    fileMenu->Append(MENU_Split, wxT("Split..."), wxEmptyString, wxITEM_NORMAL);
    fileMenu->Append(MENU_Merge, wxT("Merge..."), wxEmptyString, wxITEM_NORMAL);
    fileMenu->Append(wxID_EXIT, wxT("&Quit"), wxEmptyString, wxITEM_NORMAL);
    menuBar->Append(fileMenu, wxT("File"));
    SetMenuBar(menuBar);
    instructions = new wxStaticText(this, wxID_ANY, wxT("Drag and drop a file to split, or a folder to merge."), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE);

    set_properties();
    do_layout();
    // end wxGlade
}


BEGIN_EVENT_TABLE(AtqueWindow, wxFrame)
    // begin wxGlade: AtqueWindow::event_table
    EVT_MENU(wxID_ABOUT, AtqueWindow::OnAbout)
    EVT_MENU(MENU_Split, AtqueWindow::OnSplit)
    EVT_MENU(MENU_Merge, AtqueWindow::OnMerge)
    EVT_MENU(wxID_EXIT, AtqueWindow::OnExit)
    // end wxGlade
END_EVENT_TABLE();


void AtqueWindow::OnAbout(wxCommandEvent &event)
{
    wxMessageBox(wxT("Atque (C) 2008 Gregory Smith\n\nAtque is licensed under the GNU GPL. See COPYING.txt"), wxT("About Atque"), wxOK);
}


void AtqueWindow::OnMerge(wxCommandEvent &event)
{
    // find a directory to merge
    wxDirDialog *openDirDialog = new wxDirDialog(this,
						 wxT("Choose a folder to merge"),
						 wxT(""),
						 wxDD_DIR_MUST_EXIST | wxDD_CHANGE_DIR);
    if (openDirDialog->ShowModal() == wxID_OK)
    {
	Merge(openDirDialog->GetPath());
    }
}


void AtqueWindow::OnSplit(wxCommandEvent &event)
{
    // find the user's file
    wxFileDialog *openFileDialog = new wxFileDialog(this,
						    wxT("Choose file"),
						    wxT(""),
						    wxT(""),
						    wxT("Scenario files|*.sceA;*.imgA|All files|*.*"),
						    wxOPEN | wxCHANGE_DIR);
    if (openFileDialog->ShowModal() == wxID_OK)
    {
	Split(openFileDialog->GetPath());
    }
}


void AtqueWindow::OnExit(wxCommandEvent &event)
{
	Close(TRUE);
}


// wxGlade: add AtqueWindow event handlers

void AtqueWindow::Split(const wxString& file)
{
    // find the split destination
    wxFileDialog *saveFileDialog = new wxFileDialog(this,
						    wxT("Split files into folder:"),
						    wxT(""),
						    wxT("Split Map Folder"),
						    wxT(""),
						    wxSAVE | wxCHANGE_DIR | wxOVERWRITE_PROMPT);
    if (saveFileDialog->ShowModal() == wxID_OK)
    {
	wxBusyCursor busy;
	wxString filename = saveFileDialog->GetPath();
	if (wxFileName::FileExists(filename))
	{
	    wxRemoveFile(filename);
	}
	atque::split(std::string(file.mb_str()), std::string(filename.mb_str()), std::cout);
    }
}

void AtqueWindow::Merge(const wxString& folder)
{
    // find the merge destination
    wxFileDialog *saveFileDialog = new wxFileDialog(this,
						    wxT("Merge files into:"),
						    wxT(""),
						    wxT("Merged Map Files.sceA"),
						    wxT(""),
						    wxSAVE | wxCHANGE_DIR | wxOVERWRITE_PROMPT);
    if (saveFileDialog->ShowModal() == wxID_OK)
    {
	wxBusyCursor busy;
	wxString filename = saveFileDialog->GetPath();
	atque::merge(std::string(folder.mb_str()), std::string(filename.mb_str()), std::cout);
    }
}

void AtqueWindow::set_properties()
{
    // begin wxGlade: AtqueWindow::set_properties
    SetTitle(wxT("Atque"));
    // end wxGlade
}


void AtqueWindow::do_layout()
{
    // begin wxGlade: AtqueWindow::do_layout
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(instructions, 0, wxALL, 10);
    SetSizer(sizer);
    sizer->Fit(this);
    Layout();
    // end wxGlade
}



class Atque: public wxApp {
public:
    bool OnInit();
};

IMPLEMENT_APP(Atque)

bool Atque::OnInit()
{
    wxInitAllImageHandlers();
    AtqueWindow* Frame = new AtqueWindow(NULL, wxID_ANY, wxEmptyString);
    SetTopWindow(Frame);
    Frame->Show();
    return true;
}





