#pragma once

// C3DScene модель отображаемой сцены
#include "C3DItem.h"
#include "C3DBox.h"
#include "C3DPyramid.h"
#include "C3DSphere.h"
#include "C3DScene.h"



class C3DScene : public CObject
{
public:
	C3DScene();
	virtual ~C3DScene();
	DECLARE_SERIAL(C3DScene)
	virtual void Serialize(CArchive& ar);
	// Добавить на сцену параллелепипед
	void AddBox(C3DBox* box);
	// Удалить со сцены объект
	void RemoveObject(int idx);
	// Добавить объект через диалог
	C3DBox* AddBoxViaDialog(void);
	// набор объектов на сцене
	CArray<C3DItem*, C3DItem*> m_object_list;
	// Освобождение ресурсов, занимаемых классом
	void Clear(void);
	// модифицировать параметры объекта
	C3DItem* ModifyObject(int idx);
	// Отобразить сцену
	void Draw(void);
	// Добавить на сцену пирамиду
	void AddPyramid(C3DPyramid* pyramid);
	// Добавить пирамиду через диалог
	C3DPyramid* AddPyramidViaDialog(void);
	// Добавить шар на сцену
	void AddSphere(C3DSphere* sphere);
	// Добавить шар через диалог
	C3DSphere* AddSphereViaDialog(void);
};


