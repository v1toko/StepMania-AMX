#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
/*
-----------------------------------------------------------------------------
 Class: GameManager

 Desc: Manages GameDefs (which define different games, like "dance" and "pump")
	and StyleDefs (which define different games, like "single" and "couple")

 Copyright (c) 2001-2002 by the person(s) listed below.  All rights reserved.
	Chris Danford
-----------------------------------------------------------------------------
*/
#include "GameDef.h"
#include "StyleDef.h"
#include "Style.h"
#include "Game.h"
#include "ModeChoice.h"
class IniFile;


class GameManager
{
public:
	GameManager();
	~GameManager();

	GameDef*	GetGameDefForGame( Game g );
	const StyleDef*	GetStyleDefForStyle( Style s );

	void	GetStylesForGame( Game game, vector<Style>& aStylesAddTo, bool editor=false );
	void	GetModesChoicesForGame( Game game, vector<ModeChoice*>& apChoicesAddTo );
	void	GetNotesTypesForGame( Game game, vector<NotesType>& aNotesTypeAddTo );
	Style	GetEditorStyleForNotesType( NotesType nt );

//	void GetGameNames( CStringArray &AddTo );
//	bool DoesGameExist( CString sGameName );

	CString GetCurNoteSkinDir();

	void GetNoteSkinNames( Game game, CStringArray &AddTo ) const;
	void GetNoteSkinNames( CStringArray &AddTo ) const;	// looks up current Game in GAMESTATE
	bool DoesNoteSkinExist( CString sSkinName ) const;	// looks up current Game in GAMESTATE
	void SwitchNoteSkin( CString sNewNoteSkin );	// looks up current Game in GAMESTATE
	CString GetCurNoteSkin() const { return m_sCurNoteSkin; };

	CString GetPathTo( const int col, CString sElementName );

	CString		GetMetric( CString sClassName, CString sValueName );
	int			GetMetricI( CString sClassName, CString sValueName );
	float		GetMetricF( CString sClassName, CString sValueName );
	bool		GetMetricB( CString sClassName, CString sValueName );
	RageColor	GetMetricC( CString sClassName, CString sValueName );


	void GetEnabledGames( vector<Game>& aGamesOut );

	static int NotesTypeToNumTracks( NotesType nt );
	static NotesType StringToNotesType( CString sNotesType );
	static CString NotesTypeToString( NotesType nt );
	static Game StringToGameType( CString sGameType );

protected:

	CString m_sCurNoteSkin;	
	IniFile* m_pIniFile;
};

extern GameManager*	GAMEMAN;	// global and accessable from anywhere in our program

#endif
