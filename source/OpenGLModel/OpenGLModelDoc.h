
// OpenGLModelDoc.h : ��������� ������ COpenGLModelDoc
//


#pragma once
#include "c3dscene.h"


class COpenGLModelDoc : public CDocument
{
protected: // ������� ������ �� ������������
	COpenGLModelDoc();
	DECLARE_DYNCREATE(COpenGLModelDoc)

// ��������
public:

// ��������
public:

// ���������������
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ����������
public:
	virtual ~COpenGLModelDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ��������� ������� ����� ���������
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ��������������� �������, �������� ���������� ������ ��� ����������� ������
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	// ������ 3-� ������ �����
	C3DScene m_scene;
};
