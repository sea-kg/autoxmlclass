
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * autoxmlclass � 2013-2015 sea-kg (mrseakg@gmail.com)          *
 * source code of autoxmlclass:                            *
 *        https://github.com/sea-kg/autoxmlclass/          *
 *                                                         * 
 * Attention:                                              *
 *  It's code was generated on server:                     *
 *        http://localhost/autoxmlclass/index.php
 *  and please NOT CHANGING this code!!!                   *
 *                                                         *  
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "testObject.h"

namespace testObject {
	

	//-------------------------------

	QString _SQLSelect::nameOfElement() {
		return "SQLSelect";
	};

	//-------------------------------

	bool _SQLSelect::hasBody() {
		return true;
	};

	//-------------------------------

	bool _SQLSelect::setBody(QString body) {
		Body = body;
		return true;
	};

	//-------------------------------

	bool _SQLSelect::setAttribute(QString name, QString value) {
		if(name == "table")
			table = value;
		else
			return false;
		return true;
	}

	//-------------------------------

	bool _SQLSelect::addChildElement(QString /*strName*/, _specXMLElement */*pElem*/) {
		return false;
	};
		
	//-------------------------------


	//-------------------------------

	QString _Field::nameOfElement() {
		return "Field";
	};

	//-------------------------------

	bool _Field::hasBody() {
		return true;
	};

	//-------------------------------

	bool _Field::setBody(QString body) {
		Body = body;
		return true;
	};

	//-------------------------------

	bool _Field::setAttribute(QString name, QString value) {
		if(name == "name")
			name = value;
		else if(name == "value")
			value = value;
		else if(name == "Attr2")
			Attr2 = value;
		else if(name == "id")
			id = value;
		else if(name == "Attr1")
			Attr1 = value;
		else if(name == "Attr4")
			Attr4 = value;
		else if(name == "Attr3")
			Attr3 = value;
		else if(name == "Attr5")
			Attr5 = value;
		else
			return false;
		return true;
	}

	//-------------------------------

	bool _Field::addChildElement(QString strName, _specXMLElement *pElem) {
		if(strName == "Field") {
			_Field *p = dynamic_cast<_Field *>(pElem);
			if(p == NULL) return false;
			Fields << p;
		}
		else
			return false;
		return true;
	};

		
	//-------------------------------


	//-------------------------------

	QString _Object::nameOfElement() {
		return "Object";
	};

	//-------------------------------

	bool _Object::hasBody() {
		return true;
	};

	//-------------------------------

	bool _Object::setBody(QString body) {
		Body = body;
		return true;
	};

	//-------------------------------

	bool _Object::setAttribute(QString name, QString value) {
		if(name == "id")
			id = value;
		else if(name == "date")
			date = value;
		else
			return false;
		return true;
	}

	//-------------------------------

	bool _Object::addChildElement(QString strName, _specXMLElement *pElem) {
		if(strName == "Field") {
			_Object *p = dynamic_cast<_Field *>(pElem);
			if(p == NULL) return false;
			Fields << p;
		}
		else if(strName == "SQLSelect") {
			SQLSelect = dynamic_cast<_SQLSelect *>(pElem);
		}
		else
			return false;
		return true;
	};

		
	//-------------------------------


	//-------------------------------

	QString _Objects::nameOfElement() {
		return "Objects";
	};

	//-------------------------------

	bool _Objects::hasBody() {
		return false;
	};

	//-------------------------------

	bool _Objects::setBody(QString /*body*/) {
		 return false;
	};

	//-------------------------------

	bool _Objects::setAttribute(QString name, QString value) {
		if(name == "date")
			date = value;
		else if(name == "export")
			export = value;
		else
			return false;
		return true;
	}

	//-------------------------------

	bool _Objects::addChildElement(QString strName, _specXMLElement *pElem) {
		if(strName == "Object") {
			_Objects *p = dynamic_cast<_Object *>(pElem);
			if(p == NULL) return false;
			Objects << p;
		}
		else
			return false;
		return true;
	};

		
	//-------------------------------
 
	_specXMLElement * createElement(QString strName) {
		_specXMLElement *elem = NULL;	

		if(strName == "SQLSelect") elem = new _SQLSelect();
		if(strName == "Field") elem = new _Field();
		if(strName == "Object") elem = new _Object();
		if(strName == "Objects") elem = new _Objects();
		return elem;
	};
	
	//-------------------------------

	
	_Objects * readFromXML(QString fileXml) {
		_Objects *root = NULL;

		// init xml stream
		QFile file(fileXml);
		QXmlStreamReader xmlReader;
	
		//QString line;
		if ( !file.open(QIODevice::ReadOnly) )
			return false;
	
		{
			QTextStream t( &file );
			// stream.setCodec("CP-866");
			xmlReader.addData(t.readAll());
		}	
	
		// start reading
		QStack<_specXMLElement *> stackElements;
		while(!xmlReader.atEnd()) 
		{
			if(xmlReader.isCharacters() && stackElements.count() != 0)
			{
				_specXMLElement *pElemTop = stackElements.top();
				if(pElemTop->hasBody())
				  pElemTop->setBody(xmlReader.readElementText());
			}
		
			if(xmlReader.isStartElement())
			{ 
				QString strName = xmlReader.name().toString();
				_specXMLElement *elem = createElement(strName);
			
				_specXMLElement *parentElem = (stackElements.count() != 0) ? stackElements.top() : NULL;

				if(stackElements.count() == 0)
					root = (_Objects *)elem;
								
				if(parentElem != NULL)
					parentElem->addChildElement(strName,elem);

				stackElements.push(elem);
			
				for(int i = 0;  i < xmlReader.attributes().count(); i++)
				{
					QXmlStreamAttribute attr = xmlReader.attributes().at(i);
					elem->setAttribute(attr.name().toString(), attr.value().toString());
				}
			}
		
			if(xmlReader.isEndElement())
			{
				stackElements.pop();
			}
			xmlReader.readNext();		

		};
	
		if(xmlReader.hasError())
		{
			return NULL;
			// std::cout << xmlReader.errorString().toStdString();
		}
	
		return root;
	};

} // namespace testObject
