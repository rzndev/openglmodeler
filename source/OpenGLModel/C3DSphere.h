#pragma once
#include "c3ditem.h"
class C3DSphere :
	public C3DItem
{
public:
	C3DSphere(void);
	virtual ~C3DSphere(void);
	virtual void Serialize(CArchive& ar);
	// Отобразить объект на сцене
	virtual void Draw(void);
	// Получить свойства объекта для отображения
	virtual CString GetProperties(void);
	// Модифицировать параметры объекта
	virtual void ModifyProperties(void);


	DECLARE_SERIAL(C3DSphere)
	// радиус сферы
	double m_r;
	// количество делений вокруг оси oZ
	int m_slices;
	// количество делений вдоль оси oZ
	int m_stacks;
};

