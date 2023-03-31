#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"

#include <memory>
namespace tgdk
{
	class TGDK_API Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger> get_core_logger() { return s_core_logger; }
		inline static std::shared_ptr<spdlog::logger> get_client_logger() { return s_client_logger; }
	private:
		static std::shared_ptr<spdlog::logger> s_core_logger;
		static std::shared_ptr<spdlog::logger> s_client_logger;
	};
}
// core log macros
#define TGDK_CORE_FATAL(...)	::tgdk::Log::get_core_logger()->fatal(__VA_ARGS__)
#define TGDK_CORE_ERROR(...)	::tgdk::Log::get_core_logger()->error(__VA_ARGS__)
#define TGDK_CORE_WARN(...)		::tgdk::Log::get_core_logger()->warn(__VA_ARGS__)
#define TGDK_CORE_INFO(...)		::tgdk::Log::get_core_logger()->info(__VA_ARGS__)
#define TGDK_CORE_TRACE(...)	::tgdk::Log::get_core_logger()->trace(__VA_ARGS__)

// client log macros
#define TGDK_FATAL(...)			::tgdk::Log::get_client_logger()->fatal(__VA_ARGS__)
#define TGDK_ERROR(...)			::tgdk::Log::get_client_logger()->error(__VA_ARGS__)
#define TGDK_WARN(...)			::tgdk::Log::get_client_logger()->warn(__VA_ARGS__)
#define TGDK_INFO(...)			::tgdk::Log::get_client_logger()->info(__VA_ARGS__)
#define TGDK_TRACE(...)			::tgdk::Log::get_client_logger()->trace(__VA_ARGS__)


