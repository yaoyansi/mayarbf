/*---------------------------------------------------------------------------------------------
This file is part of Luna - the elvish ray renderer plug-in for Maya.
Copyright (C) 2010  yaoyansi

Luna is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Luna is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
---------------------------------------------------------------------------------------------*/
#include "util.h"

//
std::string int2str(int i)
{
	char buf[64];
	sprintf_s(buf, 64, "%d", i);
	return buf;
}

//
template<class T>
T* getNodePtr()
{
	_LogFunctionCall("getNodePtr()");

	MItDependencyNodes depIt(MFn::kPluginDependNode);
	for (; !depIt.isDone(); depIt.next()) 
	{
		MObject obj = depIt.thisNode();
		if (MFnDependencyNode(obj).typeId() == T::typeId) 
		{
			MFnDependencyNode fnNode(obj);
			particleAttrNode *context = dynamic_cast<T*>(fnNode.userNode());
			assert(context!=NULL);
			return context;
		}
	}
	assert(0&&"Node not exist.");
	return NULL;
}

