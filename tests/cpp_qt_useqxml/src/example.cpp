// Namespace: example
// File: example.cpp

// autoxmlclass © 2013-2015 sea-kg (mrseakg@gmail.com)
// open source code: https://github.com/sea-kg/autoxmlclass/
// Attention:
//     This file was automaticly generate on http://192.168.0.227/autoxmlclass/generate.php
// 2015 Aug 04 22:33

namespace example {

// ------------------------------------------------------------

QString Objects::nameOfElement() { 
	 return "Objects";
}

// ------------------------------------------------------------

void Objects::setdate(const QString &newval) { 
	m_sdate = newval;
}

// ------------------------------------------------------------

QString Objects::getdate() { 
	return m_sdate;
}

// ------------------------------------------------------------

void Objects::setexport(const QString &newval) { 
	m_sexport = newval;
}

// ------------------------------------------------------------

QString Objects::getexport() { 
	return m_sexport;
}

// ------------------------------------------------------------

void Objects::addObject(Object *pNewval) { 
	m_vObject.push_back(pNewval);
}

// ------------------------------------------------------------

QVector<Object*> &Objects::getVectorObject() { 
	return m_vObject;
}

// ------------------------------------------------------------

QString Object::nameOfElement() { 
	 return "Object";
}

// ------------------------------------------------------------

void Object::setid(const QString &newval) { 
	m_sid = newval;
}

// ------------------------------------------------------------

QString Object::getid() { 
	return m_sid;
}

// ------------------------------------------------------------

void Object::setdate(const QString &newval) { 
	m_sdate = newval;
}

// ------------------------------------------------------------

QString Object::getdate() { 
	return m_sdate;
}

// ------------------------------------------------------------

void Object::addField(Field *pNewval) { 
	m_vField.push_back(pNewval);
}

// ------------------------------------------------------------

QVector<Field*> &Object::getVectorField() { 
	return m_vField;
}

// ------------------------------------------------------------

void Object::setSQLSelect(SQLSelect *pNewval) { 
	m_pSQLSelect = pNewval;
}

// ------------------------------------------------------------

SQLSelect *Object::getSQLSelect() { 
	return m_pSQLSelect;
}

// ------------------------------------------------------------

QString Field::nameOfElement() { 
	 return "Field";
}

// ------------------------------------------------------------

void Field::setname(const QString &newval) { 
	m_sname = newval;
}

// ------------------------------------------------------------

QString Field::getname() { 
	return m_sname;
}

// ------------------------------------------------------------

void Field::setvalue(const QString &newval) { 
	m_svalue = newval;
}

// ------------------------------------------------------------

QString Field::getvalue() { 
	return m_svalue;
}

// ------------------------------------------------------------

void Field::setAttr2(const QString &newval) { 
	m_sAttr2 = newval;
}

// ------------------------------------------------------------

QString Field::getAttr2() { 
	return m_sAttr2;
}

// ------------------------------------------------------------

void Field::setid(const QString &newval) { 
	m_sid = newval;
}

// ------------------------------------------------------------

QString Field::getid() { 
	return m_sid;
}

// ------------------------------------------------------------

void Field::setAttr4(const QString &newval) { 
	m_sAttr4 = newval;
}

// ------------------------------------------------------------

QString Field::getAttr4() { 
	return m_sAttr4;
}

// ------------------------------------------------------------

void Field::setAttr1(const QString &newval) { 
	m_sAttr1 = newval;
}

// ------------------------------------------------------------

QString Field::getAttr1() { 
	return m_sAttr1;
}

// ------------------------------------------------------------

void Field::setAttr5(const QString &newval) { 
	m_sAttr5 = newval;
}

// ------------------------------------------------------------

QString Field::getAttr5() { 
	return m_sAttr5;
}

// ------------------------------------------------------------

void Field::setAttr3(const QString &newval) { 
	m_sAttr3 = newval;
}

// ------------------------------------------------------------

QString Field::getAttr3() { 
	return m_sAttr3;
}

// ------------------------------------------------------------

void Field::addField(Field *pNewval) { 
	m_vField.push_back(pNewval);
}

// ------------------------------------------------------------

QVector<Field*> &Field::getVectorField() { 
	return m_vField;
}

// ------------------------------------------------------------

QString SQLSelect::nameOfElement() { 
	 return "SQLSelect";
}

// ------------------------------------------------------------

void SQLSelect::settable(const QString &newval) { 
	m_stable = newval;
}

// ------------------------------------------------------------

QString SQLSelect::gettable() { 
	return m_stable;
}

} // namespace example
