
#include "log.h"
#include "prerequest_std.h"
//#include <mmgr.h>

using namespace std;

std::ofstream _logfile;

void init_logs(const std::string &logfile) 
{
	//_LogFunctionCall("init_logs()");

	_logfile.open(logfile.c_str());
	_Log("create log file: " + logfile);
}

void close_logs()
{
	//_LogFunctionCall("close_logs()");
	_logfile.close();
}

//
namespace XingXing
{
	//////////////////////////////////////////////////////////////////////////
	const string LogRootDirectroy = "d:/sthpw/xx_plugin_log/";
	//////////////////////////////////////////////////////////////////////////
	LogManager* LogManager::m_instance = NULL;
	LogManager* LogManager::getInstance()
	{
		if(m_instance==NULL)
		{
			m_instance = new LogManager();
		}
		return m_instance;
	}
	void LogManager::delInstance()
	{
		if(m_instance)
		{
			delete m_instance;
			m_instance = NULL;
		}
	}
	void LogManager::initLogFile(const std::string&logPrefix)
	{
		_initLogFile(LogRootDirectroy+logPrefix+".log");
		//_setMemoryLogFile(LogRootDirectroy+logPrefix+".mlog");
		//_setMemoryLeakLogFile(LogRootDirectroy+logPrefix+".mlk");
	}
	void LogManager::_initLogFile(const std::string&filename)
	{
		_logfile.open(filename.c_str());
		_Log("create log file: " <<filename);
	}
	void LogManager::closeLogFile()
	{
		_logfile.close();
	}
// 	void LogManager::_setMemoryLogFile(const std::string&filename)
// 	{
// 		memoryLogFile = (char*)filename.c_str();
// 	}
// 	void LogManager::_setMemoryLeakLogFile(const std::string&filename)
// 	{
// 		memoryLeakLogFile = (char*)filename.c_str();
// 	}

}