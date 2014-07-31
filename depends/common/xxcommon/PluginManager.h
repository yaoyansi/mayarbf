#ifndef _PLUGIN_MANAGER_
#define _PLUGIN_MANAGER_

#include "prerequest_std.h"

namespace XingXing
{
	class PluginManager
	{
	public:
		static PluginManager* getInstance();
		static void		   delInstance();

		void init(const char* pluginname);
		void uninit();


	private:
		PluginManager(){}
		virtual ~PluginManager(){}
		PluginManager(const PluginManager& ){}
		PluginManager& operator =(const PluginManager&){}

		void _init(	const std::string &logfile );

		static PluginManager* m_instance;

	};
}

#endif//_PLUGIN_MANAGER_