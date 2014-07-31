#ifndef _3DS_LOG_
#define _3DS_LOG_

#include <fstream>
#include <string>
#include <iostream>

extern std::ofstream _logfile;
//
#ifndef _SIMPLE_TEST_
	#ifdef _DEBUG 
		#define _Log(log)		_logfile  << log << std::endl; \
								std::cout << log << std::endl;
		#define _LogDebug(log)	_logfile  << log << std::endl; \
								std::cout << log << std::endl;
		#define _LogError(log)	_logfile  <<"ERROR:"<<log << std::endl; \
								std::cout <<"ERROR:"<<log << std::endl;
		#define _LogWarn(log)	_logfile  <<"WARN:"<<log << std::endl; \
								_logfile  <<"WARN:"<<log << std::endl; 
		#define _LogFunctionCall(log)	_logfile << "CALL:" << log << std::endl; \
										std::cout<< "CALL:" << log << std::endl;
// 		#define _LogFunctionLoopCall(log, x) 	static size_t count=0;		\
// 												count++;					\
// 												if((count %(x))==1){		\
// 													std::cout << "CALL:" << (log) ;	\
// 												}else if((count %(x))==0){	\
// 													std::cout << "\n";		\
// 													count = (x);			\
// 												}else{						\
// 													std::cout << "." ;		\
// 												}
	#else 
	// 	#define _Log(log)  std::cout << log << std::endl;
	// 	#define _LogDebug(log) _logfile << log << std::endl;
	// 	#define _LogFunctionCall(log) 
		#define _Log(log)       _logfile  <<log << std::endl; \
								std::cout <<log << std::endl;
		#define _LogError(log)	_logfile  <<"ERROR:"<<log << std::endl; \
								std::cout <<"ERROR:"<<log << std::endl;
		#define _LogWarn(log)	_logfile  <<"WARN:"<<log << std::endl; 
		#define _LogDebug(log)
		#define _LogFunctionCall(log)	
	#endif
#else//!_SIMPLE_TEST_
	#ifdef _DEBUG 
		#define _Log(log)			std::cout << log << std::endl;
		#define _LogDebug(log)		std::cout << log << std::endl;
		#define _LogError(log)		std::cout <<"ERROR:"<<log << std::endl;
		#define _LogFunctionCall(log)		std::cout<< "CALL:" << log << std::endl;
	#else 
		#define _Log(log)			std::cout <<log << std::endl;
		#define _LogError(log)		std::cout <<"ERROR:"<<log << std::endl;
		#define _LogDebug(log)
		#define _LogFunctionCall(log) 
	#endif
#endif//_SIMPLE_TEST_

//
void init_logs(const std::string &logfile);
void close_logs();

//
namespace XingXing
{
	class LogManager
	{
	public:
		static LogManager* getInstance();
		static void		   delInstance();

		static void initLogFile(const std::string&fileNamePrefix);
		static void closeLogFile();



	private:
		LogManager(){}
		virtual ~LogManager(){}
		LogManager(const LogManager& ){}
		LogManager& operator =(const LogManager&){}

		static void _initLogFile(const std::string&filename);
// 		static void _setMemoryLogFile(const std::string&filename);
// 		static void _setMemoryLeakLogFile(const std::string&filename);

		static LogManager* m_instance;

	};
}
#endif
