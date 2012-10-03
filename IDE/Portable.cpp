/** \file
 *  Game Develop
 *  2008-2012 Florian Rival (Florian.Rival@gmail.com)
 */

//(*InternalHeaders(Portable)
#include <wx/bitmap.h>
#include <wx/settings.h>
#include <wx/intl.h>
#include <wx/image.h>
#include <wx/string.h>
//*)
#include <string>
#include <vector>
#include <wx/dirdlg.h>
#include <wx/log.h>
#include <wx/filename.h>
#include "GDCore/IDE/ResourcesMergingHelper.h"
#include "GDCore/CommonTools.h"
#include "GDL/PlatformDefinition/Platform.h"
#include "GDL/ExternalEvents.h"
#include "GDL/Game.h"
#include "GDL/Object.h"
#include "GDL/Scene.h"
#include "GDL/OpenSaveGame.h"
#include "Portable.h"

using namespace std;

//(*IdInit(Portable)
const long Portable::ID_STATICBITMAP1 = wxNewId();
const long Portable::ID_STATICTEXT1 = wxNewId();
const long Portable::ID_PANEL1 = wxNewId();
const long Portable::ID_STATICLINE1 = wxNewId();
const long Portable::ID_GAUGE1 = wxNewId();
const long Portable::ID_STATICLINE2 = wxNewId();
const long Portable::ID_STATICTEXT2 = wxNewId();
const long Portable::ID_BUTTON1 = wxNewId();
const long Portable::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Portable,wxDialog)
	//(*EventTable(Portable)
	//*)
END_EVENT_TABLE()

Portable::Portable(wxWindow* parent, Game * pgame) :
jeu(pgame)
{
	//(*Initialize(Portable)
	wxFlexGridSizer* FlexGridSizer2;
	wxFlexGridSizer* FlexGridSizer6;
	wxStaticBoxSizer* StaticBoxSizer1;
	wxFlexGridSizer* FlexGridSizer1;
	wxFlexGridSizer* FlexGridSizer17;

	Create(parent, wxID_ANY, _("Save the game in portable version"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	wxIcon FrameIcon;
	FrameIcon.CopyFromBitmap(wxBitmap(wxImage(_T("res/portableicon.png"))));
	SetIcon(FrameIcon);
	FlexGridSizer1 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer17 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer17->AddGrowableCol(0);
	Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxSize(420,54), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	Panel1->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
	FlexGridSizer6 = new wxFlexGridSizer(0, 3, 0, 0);
	StaticBitmap1 = new wxStaticBitmap(Panel1, ID_STATICBITMAP1, wxBitmap(wxImage(_T("res/portable.png"))), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICBITMAP1"));
	FlexGridSizer6->Add(StaticBitmap1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Save the game in portable version allow to\ngather every ressources used by the game in a folder\nand to open this game in another computer."), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE, _T("ID_STATICTEXT1"));
	FlexGridSizer6->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Panel1->SetSizer(FlexGridSizer6);
	FlexGridSizer6->SetSizeHints(Panel1);
	FlexGridSizer17->Add(Panel1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	StaticLine1 = new wxStaticLine(this, ID_STATICLINE1, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
	FlexGridSizer17->Add(StaticLine1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	FlexGridSizer1->Add(FlexGridSizer17, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Progress"));
	AvancementGauge = new wxGauge(this, ID_GAUGE1, 100, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_GAUGE1"));
	StaticBoxSizer1->Add(AvancementGauge, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(StaticBoxSizer1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticLine2 = new wxStaticLine(this, ID_STATICLINE2, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE2"));
	FlexGridSizer1->Add(StaticLine2, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	FlexGridSizer2 = new wxFlexGridSizer(0, 3, 0, 0);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("It is recommended to use an empty directory."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	FlexGridSizer2->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FusionBt = new wxButton(this, ID_BUTTON1, _("Choose a folder and save"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	FlexGridSizer2->Add(FusionBt, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FermerBt = new wxButton(this, ID_BUTTON2, _("Close"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	FlexGridSizer2->Add(FermerBt, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(FlexGridSizer2, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 0);
	SetSizer(FlexGridSizer1);
	FlexGridSizer1->Fit(this);
	FlexGridSizer1->SetSizeHints(this);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Portable::OnButton1Click);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Portable::OnButton2Click);
	//*)
}

Portable::~Portable()
{
	//(*Destroy(Portable)
	//*)
}


void Portable::OnButton2Click(wxCommandEvent& event)
{
    EndModal(0);
}

void Portable::OnButton1Click(wxCommandEvent& event)
{
    wxDirDialog dialog(this, _("Choose the directory where the game will be gather."));
    dialog.ShowModal();

    string rep = string( dialog.GetPath().mb_str() );
    if ( rep.empty() ) return;

    //Copie du jeu
    Game game = *jeu;

    gd::ResourcesMergingHelper resourcesMergingHelper;
    resourcesMergingHelper.SetBaseDirectory(gd::ToString(wxFileName::FileName(game.GetProjectFile()).GetPath()));
    resourcesMergingHelper.PreserveDirectoriesStructure(true);

    game.ExposeResources(resourcesMergingHelper);

    //Copy resources
    map<string, string> & resourcesNewFilename = resourcesMergingHelper.GetAllResourcesOldAndNewFilename();
    unsigned int i = 0;
    for(map<string, string>::const_iterator it = resourcesNewFilename.begin(); it != resourcesNewFilename.end(); ++it)
    {
        if ( !it->first.empty() )
        {
            std::string destination = rep + "/" + it->second;

            if ( !wxDirExists(wxFileName::FileName(destination).GetPath()) )
                wxMkDir(wxFileName::FileName(destination).GetPath(), 0777);

            bool copySucceeded = false;
            {
                wxLogNull noLogPlease;
                copySucceeded = wxCopyFile( it->first, destination, true );
            }
            if ( !copySucceeded ) wxLogWarning( _( "Unable to copy \"")+it->first+_("\" to \"")+destination+_("\"."));
        }

        ++i;
        AvancementGauge->SetValue( i/static_cast<float>(resourcesNewFilename.size())*50.0f + 50.0f );
        wxSafeYield();
    }

    wxString filename = game.GetProjectFile().empty() ? "Game.gdg" : wxFileName::FileName(game.GetProjectFile()).GetName()+".gdg";
    game.SaveToFile(rep+"/"+gd::ToString(filename));

    AvancementGauge->SetValue(100);
    wxLogMessage(_("The game is available in the directory under the name: ")+gd::ToString(filename));
}

