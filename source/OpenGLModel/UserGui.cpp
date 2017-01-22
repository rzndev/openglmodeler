// UserGui.cpp: файл реализации
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


// диагностика CUserGui

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


// обработчики сообщений CUserGui


void CUserGui::OnBnClickedButtonParal()
{
	C3DBox* box = NULL; // добавляемый объект
	COpenGLModelDoc* pDoc = reinterpret_cast<COpenGLModelDoc*>(GetDocument()); // получаем указатель на документ
	box = pDoc->m_scene.AddBoxViaDialog();
	if (NULL == box) return; // пользователь отменил добавление объекта
	
	CEdit* pEdit = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT_PROPERTIES));	// получаем указатель на элемент управления отображением свойств объекта
	pEdit->SetWindowText(box->GetProperties()); // устанавливаем свойства для добавленного объекта

	CListBox* pListBox = reinterpret_cast<CListBox*>(GetDlgItem(IDC_LIST1)); // получаем указатель на элемент управления со списком объектов
	pListBox->AddString(box->m_name);
	pListBox->SetCurSel(pListBox->GetCount()-1);	   // позиционируем на добавленный элемент
	pDoc->UpdateAllViews(NULL);
}


void CUserGui::OnBnClickedButtonPyramid()
{
	C3DPyramid* pyramid = NULL; // добавляемый объект
	COpenGLModelDoc* pDoc = reinterpret_cast<COpenGLModelDoc*>(GetDocument()); // получаем указатель на документ
	pyramid = pDoc->m_scene.AddPyramidViaDialog();
	if (NULL == pyramid) return; // пользователь отменил добавление объекта
	
	CEdit* pEdit = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT_PROPERTIES));	// получаем указатель на элемент управления отображением свойств объекта
	pEdit->SetWindowText(pyramid->GetProperties()); // устанавливаем свойства для добавленного объекта

	CListBox* pListBox = reinterpret_cast<CListBox*>(GetDlgItem(IDC_LIST1)); // получаем указатель на элемент управления со списком объектов
	pListBox->AddString(pyramid->m_name);
	pListBox->SetCurSel(pListBox->GetCount()-1);	   // позиционируем на добавленный элемент
	pDoc->UpdateAllViews(NULL);
}


void CUserGui::OnBnClickedButtonSphere()
{
	C3DSphere* sphere = NULL; // добавляемый объект
	COpenGLModelDoc* pDoc = reinterpret_cast<COpenGLModelDoc*>(GetDocument()); // получаем указатель на документ
	sphere = pDoc->m_scene.AddSphereViaDialog();
	if (NULL == sphere) return; // пользователь отменил добавление объекта
	
	CEdit* pEdit = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT_PROPERTIES));	// получаем указатель на элемент управления отображением свойств объекта
	pEdit->SetWindowText(sphere->GetProperties()); // устанавливаем свойства для добавленного объекта

	CListBox* pListBox = reinterpret_cast<CListBox*>(GetDlgItem(IDC_LIST1)); // получаем указатель на элемент управления со списком объектов
	pListBox->AddString(sphere->m_name);
	pListBox->SetCurSel(pListBox->GetCount()-1);	   // позиционируем на добавленный элемент
	pDoc->UpdateAllViews(NULL);
}


// удаление объекта
void CUserGui::OnBnClickedButtonRemove()
{
	CListBox* pListBox = reinterpret_cast<CListBox*>(GetDlgItem(IDC_LIST1)); // получаем указатель на элемент управления со списком объектов
	if (pListBox->GetCurSel() == -1) return; // ни один элемент в списке не выбран - действий не производим

	COpenGLModelDoc* pDoc = reinterpret_cast<COpenGLModelDoc*>(GetDocument()); // получаем указатель на документ
	if (pListBox->GetCurSel() > pDoc->m_scene.m_object_list.GetUpperBound()) return; // индекс за пределами допустимого значения
	pDoc->m_scene.RemoveObject(pListBox->GetCurSel());
	pListBox->DeleteString(pListBox->GetCurSel());
	ShowPropertiesCurrentObject(); // отображаем свойства текущего объекта
	pDoc->UpdateAllViews(NULL);
}

// изменение параметров объекта
void CUserGui::OnBnClickedButtonModify()
{
	C3DItem* item = NULL;
	CListBox* pListBox = reinterpret_cast<CListBox*>(GetDlgItem(IDC_LIST1)); // получаем указатель на элемент управления со списком объектов
	if (pListBox->GetCurSel() == -1) return; // ни один элемент в списке не выбран - действий не производим
	COpenGLModelDoc* pDoc = reinterpret_cast<COpenGLModelDoc*>(GetDocument()); // получаем указатель на документ
	if (pListBox->GetCurSel() > pDoc->m_scene.m_object_list.GetUpperBound()) return; // индекс за пределами допустимого значения
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
	int nElems; // индекс последнего элемента списка
	int i;      // вспомогательная переменная
	COpenGLModelDoc* pDoc = reinterpret_cast<COpenGLModelDoc*>(GetDocument()); // получаем указатель на документ
	CFormView::OnInitialUpdate();
	m_opengl.InitWindow();
	m_opengl.m_pScene = &pDoc->m_scene; // устанавливаем указатель на модель сцены для отображения

	// заполняем список объектов
	CListBox* pListBox = reinterpret_cast<CListBox*>(GetDlgItem(IDC_LIST1)); // получаем указатель на элемент управления со списком объектов
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

// Отобразить свойства объекта, выделенного в списке
void CUserGui::ShowPropertiesCurrentObject(void)
{
	COpenGLModelDoc* pDoc = reinterpret_cast<COpenGLModelDoc*>(GetDocument()); // получаем указатель на документ
	CListBox* pListBox = reinterpret_cast<CListBox*>(GetDlgItem(IDC_LIST1)); // получаем указатель на элемент управления со списком объектов
    CEdit* pEdit = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT_PROPERTIES));	// получаем указатель на элемент управления отображением свойств объекта
	pEdit->SetWindowText(_T("")); // очищаем свойства (на случай, если в списке нет объектов)
	if (pListBox->GetCurSel() == -1) return; // нет выбранного элемента в списке
	if (pListBox->GetCurSel() > pDoc->m_scene.m_object_list.GetUpperBound()) return; // индекс за пределами допустимого значения
	C3DItem* item = pDoc->m_scene.m_object_list.GetAt(pListBox->GetCurSel());
	if (NULL == item) return;
	pEdit->SetWindowText(item->GetProperties());
}


void CUserGui::OnSelchangeList1()
{
	CListBox* pListBox = reinterpret_cast<CListBox*>(GetDlgItem(IDC_LIST1)); // получаем указатель на элемент управления со списком объектов
	if (NULL == pListBox) return;
	ShowPropertiesCurrentObject();
}
