
// OpenGLModelDoc.cpp : ���������� ������ COpenGLModelDoc
//

#include "stdafx.h"
// SHARED_HANDLERS ����� ���������� � ������������ �������� ��������� ���������� ������� ATL, �������
// � ������; ��������� ��������� ������������ ��� ��������� � ������ �������.
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


// ��������/����������� COpenGLModelDoc

COpenGLModelDoc::COpenGLModelDoc()
{
	// TODO: �������� ��� ��� ������������ ������ ������������
}

COpenGLModelDoc::~COpenGLModelDoc()
{
}

BOOL COpenGLModelDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �������� ��� ��������� �������������
	// (��������� SDI ����� �������� ������������ ���� ��������)
	
	// �������������� 3D �����
	m_scene.Clear();
	return TRUE;
}




// ������������ COpenGLModelDoc

void COpenGLModelDoc::Serialize(CArchive& ar)
{
	m_scene.Serialize(ar);
	if (ar.IsStoring())
	{
		// TODO: �������� ��� ����������
	}
	else
	{
		// TODO: �������� ��� ��������
	}
}

#ifdef SHARED_HANDLERS

// ��������� ��� �������
void COpenGLModelDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �������� ���� ��� ��� ����������� ������ ���������
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

// ��������� ������������ ������
void COpenGLModelDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ������� ���������� ������ �� ������ ���������. 
	// ����� ����������� ������ ����������� ������ � ������� ";"

	// ��������:  strSearchContent = _T("�����;�������������;����;������ ole;");
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

// ����������� COpenGLModelDoc

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


// ������� COpenGLModelDoc
