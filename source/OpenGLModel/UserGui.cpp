// UserGui.cpp: ���� ����������
//

#include "stdafx.h"
#include "OpenGLModel.h"
#include "UserGui.h"
#include "OpenGLModelDoc.h"

// CUserGui

IMPLEMENT_DYNCREATE(CUserGui, CFormView)

CUserGui::CUserGui()
	: CFormView(CUserGui::IDD)
{

}

CUserGui::~CUserGui()
{
}

void CUserGui::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CUSTOM1, m_opengl);
}

BEGIN_MESSAGE_MAP(CUserGui, CFormView)
	ON_BN_CLICKED(IDC_BUTTON_PARAL, &CUserGui::OnBnClickedButtonParal)
	ON_BN_CLICKED(IDC_BUTTON_PYRAMID, &CUserGui::OnBnClickedButtonPyramid)
	ON_BN_CLICKED(IDC_BUTTON_SPHERE, &CUserGui::OnBnClickedButtonSphere)
	ON_BN_CLICKED(IDC_BUTTON_REMOVE, &CUserGui::OnBnClickedButtonRemove)
	ON_BN_CLICKED(IDC_BUTTON_MODIFY, &CUserGui::OnBnClickedButtonModify)
	ON_BN_CLICKED(IDC_BUTTON_VIEW_FRONT, &CUserGui::OnBnClickedButtonViewFront)
	ON_BN_CLICKED(IDC_BUTTON_VIEW_BACK, &CUserGui::OnBnClickedButtonViewBack)
	ON_BN_CLICKED(IDC_BUTTON_VIEW_LEFT, &CUserGui::OnBnClickedButtonViewLeft)
	ON_BN_CLICKED(IDC_BUTTON_RIGHT, &CUserGui::OnBnClickedButtonRight)
	ON_BN_CLICKED(IDC_BUTTON_VIEW_TOP, &CUserGui::OnBnClickedButtonViewTop)
	ON_BN_CLICKED(IDC_BUTTON_VIEW_BOTTOM, &CUserGui::OnBnClickedButtonViewBottom)
	ON_WM_DESTROY()
	ON_LBN_SELCHANGE(IDC_LIST1, &CUserGui::OnSelchangeList1)
END_MESSAGE_MAP()


// ����������� CUserGui

#ifdef _DEBUG
void CUserGui::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CUserGui::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// ����������� ��������� CUserGui


void CUserGui::OnBnClickedButtonParal()
{
	C3DBox* box = NULL; // ����������� ������
	COpenGLModelDoc* pDoc = reinterpret_cast<COpenGLModelDoc*>(GetDocument()); // �������� ��������� �� ��������
	box = pDoc->m_scene.AddBoxViaDialog();
	if (NULL == box) return; // ������������ ������� ���������� �������
	
	CEdit* pEdit = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT_PROPERTIES));	// �������� ��������� �� ������� ���������� ������������ ������� �������
	pEdit->SetWindowText(box->GetProperties()); // ������������� �������� ��� ������������ �������

	CListBox* pListBox = reinterpret_cast<CListBox*>(GetDlgItem(IDC_LIST1)); // �������� ��������� �� ������� ���������� �� ������� ��������
	pListBox->AddString(box->m_name);
	pListBox->SetCurSel(pListBox->GetCount()-1);	   // ������������� �� ����������� �������
	pDoc->UpdateAllViews(NULL);
}


void CUserGui::OnBnClickedButtonPyramid()
{
	C3DPyramid* pyramid = NULL; // ����������� ������
	COpenGLModelDoc* pDoc = reinterpret_cast<COpenGLModelDoc*>(GetDocument()); // �������� ��������� �� ��������
	pyramid = pDoc->m_scene.AddPyramidViaDialog();
	if (NULL == pyramid) return; // ������������ ������� ���������� �������
	
	CEdit* pEdit = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT_PROPERTIES));	// �������� ��������� �� ������� ���������� ������������ ������� �������
	pEdit->SetWindowText(pyramid->GetProperties()); // ������������� �������� ��� ������������ �������

	CListBox* pListBox = reinterpret_cast<CListBox*>(GetDlgItem(IDC_LIST1)); // �������� ��������� �� ������� ���������� �� ������� ��������
	pListBox->AddString(pyramid->m_name);
	pListBox->SetCurSel(pListBox->GetCount()-1);	   // ������������� �� ����������� �������
	pDoc->UpdateAllViews(NULL);
}


void CUserGui::OnBnClickedButtonSphere()
{
	C3DSphere* sphere = NULL; // ����������� ������
	COpenGLModelDoc* pDoc = reinterpret_cast<COpenGLModelDoc*>(GetDocument()); // �������� ��������� �� ��������
	sphere = pDoc->m_scene.AddSphereViaDialog();
	if (NULL == sphere) return; // ������������ ������� ���������� �������
	
	CEdit* pEdit = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT_PROPERTIES));	// �������� ��������� �� ������� ���������� ������������ ������� �������
	pEdit->SetWindowText(sphere->GetProperties()); // ������������� �������� ��� ������������ �������

	CListBox* pListBox = reinterpret_cast<CListBox*>(GetDlgItem(IDC_LIST1)); // �������� ��������� �� ������� ���������� �� ������� ��������
	pListBox->AddString(sphere->m_name);
	pListBox->SetCurSel(pListBox->GetCount()-1);	   // ������������� �� ����������� �������
	pDoc->UpdateAllViews(NULL);
}


// �������� �������
void CUserGui::OnBnClickedButtonRemove()
{
	CListBox* pListBox = reinterpret_cast<CListBox*>(GetDlgItem(IDC_LIST1)); // �������� ��������� �� ������� ���������� �� ������� ��������
	if (pListBox->GetCurSel() == -1) return; // �� ���� ������� � ������ �� ������ - �������� �� ����������

	COpenGLModelDoc* pDoc = reinterpret_cast<COpenGLModelDoc*>(GetDocument()); // �������� ��������� �� ��������
	if (pListBox->GetCurSel() > pDoc->m_scene.m_object_list.GetUpperBound()) return; // ������ �� ��������� ����������� ��������
	pDoc->m_scene.RemoveObject(pListBox->GetCurSel());
	pListBox->DeleteString(pListBox->GetCurSel());
	ShowPropertiesCurrentObject(); // ���������� �������� �������� �������
	pDoc->UpdateAllViews(NULL);
}

// ��������� ���������� �������
void CUserGui::OnBnClickedButtonModify()
{
	C3DItem* item = NULL;
	CListBox* pListBox = reinterpret_cast<CListBox*>(GetDlgItem(IDC_LIST1)); // �������� ��������� �� ������� ���������� �� ������� ��������
	if (pListBox->GetCurSel() == -1) return; // �� ���� ������� � ������ �� ������ - �������� �� ����������
	COpenGLModelDoc* pDoc = reinterpret_cast<COpenGLModelDoc*>(GetDocument()); // �������� ��������� �� ��������
	if (pListBox->GetCurSel() > pDoc->m_scene.m_object_list.GetUpperBound()) return; // ������ �� ��������� ����������� ��������
	item = pDoc->m_scene.ModifyObject(pListBox->GetCurSel());
	if (NULL == item)
	{
		ShowPropertiesCurrentObject();
		return;
	}
	int cursel = pListBox->GetCurSel();
	pListBox->DeleteString(cursel);
	pListBox->InsertString(cursel, item->m_name);
	pListBox->SetCurSel(cursel);
	ShowPropertiesCurrentObject();
	pDoc->UpdateAllViews(NULL);
}


void CUserGui::OnBnClickedButtonViewFront()
{
	m_opengl.rX = 0;
	m_opengl.rY = 0;
	m_opengl.Invalidate(FALSE);
}


void CUserGui::OnBnClickedButtonViewBack()
{
	m_opengl.rX = 180;
	m_opengl.rY = 0;
	m_opengl.Invalidate(FALSE);
}


void CUserGui::OnBnClickedButtonViewLeft()
{
	m_opengl.rX = 90;
	m_opengl.rY = 0;
	m_opengl.Invalidate(FALSE);
}


void CUserGui::OnBnClickedButtonRight()
{
	m_opengl.rX = -90;
	m_opengl.rY = 0;
	m_opengl.Invalidate(FALSE);
}


void CUserGui::OnBnClickedButtonViewTop()
{
	m_opengl.rX = 0;
	m_opengl.rY = 90;
	m_opengl.Invalidate(FALSE);
}


void CUserGui::OnBnClickedButtonViewBottom()
{
	m_opengl.rX = 0;
	m_opengl.rY = -90;
	m_opengl.Invalidate(FALSE);
}


void CUserGui::OnInitialUpdate()
{
	int nElems; // ������ ���������� �������� ������
	int i;      // ��������������� ����������
	COpenGLModelDoc* pDoc = reinterpret_cast<COpenGLModelDoc*>(GetDocument()); // �������� ��������� �� ��������
	CFormView::OnInitialUpdate();
	m_opengl.InitWindow();
	m_opengl.m_pScene = &pDoc->m_scene; // ������������� ��������� �� ������ ����� ��� �����������

	// ��������� ������ ��������
	CListBox* pListBox = reinterpret_cast<CListBox*>(GetDlgItem(IDC_LIST1)); // �������� ��������� �� ������� ���������� �� ������� ��������
	pListBox->ResetContent();
	nElems = pDoc->m_scene.m_object_list.GetUpperBound();
	for(i = 0; i <= nElems; i++)
		pListBox->AddString(pDoc->m_scene.m_object_list.GetAt(i)->m_name);
}


void CUserGui::OnDestroy()
{
//	if (m_opengl.GetSafeHwnd() != NULL)
//		m_opengl.UnsubclassWindow();
	CFormView::OnDestroy();
}

// ���������� �������� �������, ����������� � ������
void CUserGui::ShowPropertiesCurrentObject(void)
{
	COpenGLModelDoc* pDoc = reinterpret_cast<COpenGLModelDoc*>(GetDocument()); // �������� ��������� �� ��������
	CListBox* pListBox = reinterpret_cast<CListBox*>(GetDlgItem(IDC_LIST1)); // �������� ��������� �� ������� ���������� �� ������� ��������
    CEdit* pEdit = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT_PROPERTIES));	// �������� ��������� �� ������� ���������� ������������ ������� �������
	pEdit->SetWindowText(_T("")); // ������� �������� (�� ������, ���� � ������ ��� ��������)
	if (pListBox->GetCurSel() == -1) return; // ��� ���������� �������� � ������
	if (pListBox->GetCurSel() > pDoc->m_scene.m_object_list.GetUpperBound()) return; // ������ �� ��������� ����������� ��������
	C3DItem* item = pDoc->m_scene.m_object_list.GetAt(pListBox->GetCurSel());
	if (NULL == item) return;
	pEdit->SetWindowText(item->GetProperties());
}


void CUserGui::OnSelchangeList1()
{
	CListBox* pListBox = reinterpret_cast<CListBox*>(GetDlgItem(IDC_LIST1)); // �������� ��������� �� ������� ���������� �� ������� ��������
	if (NULL == pListBox) return;
	ShowPropertiesCurrentObject();
}
