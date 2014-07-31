#include "PluginManager.h"
#include "prerequest_maya.h"
#include "mayacheck.h"
#include "log.h"

using namespace std;

namespace XingXing
{
	PluginManager* PluginManager::m_instance = NULL;

	PluginManager* PluginManager::getInstance()
	{
		if(m_instance==NULL)
		{
			m_instance = new PluginManager();
		}
		return m_instance;
	}
	void PluginManager::delInstance()
	{
		if(m_instance)
		{
			delete m_instance;
			m_instance = NULL;
		}
	}
	void PluginManager::init(const char* pluginname)
	{
		//scene name
		MString fileShortName;
		IfMErrorWarn(MGlobal::executeCommand("file -q -shortName -sn", fileShortName));
		if( fileShortName.length()==0 ){//unsaved scene
			fileShortName = "untitled";
		}

		//time
		time_t rawtime;
		time(&rawtime);
		struct tm ti;
		if(localtime_s(&ti, &rawtime)){
			printf("PluginManager::init(), localtime_s() error.");
			exit(1);
		}

		char shortFileNamePrefix[512];
		sprintf_s(shortFileNamePrefix, 512, "%s_%04d_%02d_%02d_%02d_%02d_%s",
			fileShortName.asChar(),
			ti.tm_year + 1900,
			ti.tm_mon,
			ti.tm_mday,
			ti.tm_hour,
			ti.tm_min,
			pluginname
			);

		_init(shortFileNamePrefix);
	}
	void PluginManager::_init(const string &logFilePrefix )
	{
		LogManager::initLogFile(logFilePrefix);

	}
	void PluginManager::uninit()
	{
		LogManager::closeLogFile();
	}
}