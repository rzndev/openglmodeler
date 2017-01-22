#pragma once
#include <gl\GL.h>
#include <gl\GLU.h>
// конечный объект команды C3DItem

class C3DItem : public CObject
{
public:
	C3DItem();
	virtual ~C3DItem();
	virtual void Serialize(CArchive& ar);

	
	// положение объекта на оси X
	double m_X;
	// положение объекта на оси Y
	double m_Y;
	// положение объекта на оси Z
	double m_Z;
	// вращение объекта относительно оси X
	double m_rX;
	// вращение объекта относительно оси Y
	double m_rY;
	// Вращение объекта относительно переменной Z
	double m_rZ;

	// Overridables

	// Отобразить объект на сцене
	virtual void Draw(void);
	// Получить свойства объекта для отображения
	virtual CString GetProperties(void);
	// Модифицировать параметры объекта
	virtual void ModifyProperties(void);
	// имя объекта
	CString m_name;

	// подготовить систему координат для отображения объекта
	void PrepareCoords(void);
	// установить материал объекта
	void PrepareMaterial(void);
	// цвет объекта
	DWORD m_color;
	DECLARE_SERIAL(C3DItem)	
};


