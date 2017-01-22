
// OpenGLModelDoc.cpp : реализация класса COpenGLModelDoc
//

#include "stdafx.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "OpenGLModel.h"
#endif

#include "OpenGLModelDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// COpenGLModelDoc

IMPLEMENT_DYNCREATE(COpenGLModelDoc, CDocument)

BEGIN_MESSAGE_MAP(COpenGLModelDoc, CDocument)
END_MESSAGE_MAP()


// создание/уничтожение COpenGLModelDoc

COpenGLModelDoc::COpenGLModelDoc()
{
	// TODO: добавьте код для одноразового вызова конструктора
}

COpenGLModelDoc::~COpenGLModelDoc()
{
}

BOOL COpenGLModelDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: добавьте код повторной инициализации
	// (Документы SDI будут повторно использовать этот документ)
	
	// инициализируем 3D сцену
	m_scene.Clear();
	return TRUE;
}




// сериализация COpenGLModelDoc

void COpenGLModelDoc::Serialize(CArchive& ar)
{
	m_scene.Serialize(ar);
	if (ar.IsStoring())
	{
		// TODO: добавьте код сохранения
	}
	else
	{
		// TODO: добавьте код загрузки
	}
}

#ifdef SHARED_HANDLERS

// Поддержка для эскизов
void COpenGLModelDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Измените этот код для отображения данных документа
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Поддержка обработчиков поиска
void COpenGLModelDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Задайте содержимое поиска из данных документа. 
	// Части содержимого должны разделяться точкой с запятой ";"

	// Например:  strSearchContent = _T("точка;прямоугольник;круг;объект ole;");
	SetSearchContent(strSearchContent);
}

void COpenGLModelDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// диагностика COpenGLModelDoc

#ifdef _DEBUG
void COpenGLModelDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void COpenGLModelDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// команды COpenGLModelDoc
