// Namespace: example
// File: example.h

// autoxmlclass © 2013-2015 sea-kg (mrseakg@gmail.com)
// open source code: https://github.com/sea-kg/autoxmlclass/
// Attention:
//     This file was automaticly generate on http://192.168.0.227/autoxmlclass/generate.php
// 2015 Aug 04 22:33


#include<QString>
#include<QVector>

namespace example {

class Objects;
class Object;
class Field;
class SQLSelect;

class Objects {
	// base methods
	public:
		QString nameOfElement();

	// generate members attribute
	private:
		QString m_sdate;
		QString m_sexport;

	// generate members for elements
	private:
		QVector<example::Object *> m_vObject;

	// generate methods for attribute
	public:
		void setdate(const QString &newval);
		QString getdate();
		void setexport(const QString &newval);
		QString getexport();

	// generate methods for elements
	public:
		void addObject(Object *pNewval);
		QVector<Object *> &getVectorObject();

}; // class Objects

class Object {
	// base methods
	public:
		QString nameOfElement();

	// generate members attribute
	private:
		QString m_sid;
		QString m_sdate;

	// generate members for elements
	private:
		QVector<example::Field *> m_vField;
		example::SQLSelect *m_pSQLSelect;

	// generate methods for attribute
	public:
		void setid(const QString &newval);
		QString getid();
		void setdate(const QString &newval);
		QString getdate();

	// generate methods for elements
	public:
		void addField(Field *pNewval);
		QVector<Field *> &getVectorField();
		void setSQLSelect(SQLSelect *pNewval);
		SQLSelect * getSQLSelect();

}; // class Object

class Field {
	// base methods
	public:
		QString nameOfElement();

	// generate members attribute
	private:
		QString m_sname;
		QString m_svalue;
		QString m_sAttr2;
		QString m_sid;
		QString m_sAttr4;
		QString m_sAttr1;
		QString m_sAttr5;
		QString m_sAttr3;

	// generate members for elements
	private:
		QVector<example::Field *> m_vField;

	// generate methods for attribute
	public:
		void setname(const QString &newval);
		QString getname();
		void setvalue(const QString &newval);
		QString getvalue();
		void setAttr2(const QString &newval);
		QString getAttr2();
		void setid(const QString &newval);
		QString getid();
		void setAttr4(const QString &newval);
		QString getAttr4();
		void setAttr1(const QString &newval);
		QString getAttr1();
		void setAttr5(const QString &newval);
		QString getAttr5();
		void setAttr3(const QString &newval);
		QString getAttr3();

	// generate methods for elements
	public:
		void addField(Field *pNewval);
		QVector<Field *> &getVectorField();

}; // class Field

class SQLSelect {
	// base methods
	public:
		QString nameOfElement();

	// generate members attribute
	private:
		QString m_stable;

	// generate members for elements
	private:

	// generate methods for attribute
	public:
		void settable(const QString &newval);
		QString gettable();

	// generate methods for elements
	public:

}; // class SQLSelect


} // namespace example
