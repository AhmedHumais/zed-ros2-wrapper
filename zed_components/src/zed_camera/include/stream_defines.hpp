#include <type_traits>

#define RCLCPP_DEBUG_STREAM(logger, stream_arg) \
   do { \
     static_assert( \
       ::std::is_same<typename std::remove_cv<typename std::remove_reference<decltype(logger)>::type>::type, \
       typename ::rclcpp::Logger>::value, \
       "First argument to logging macros must be an rclcpp::Logger"); \
  \
     std::stringstream ss; \
     ss << stream_arg; \
     RCUTILS_LOG_DEBUG_NAMED( \
       logger.get_name(), \
       "%s", rclcpp::get_c_string(ss.str())); \
   } while (0)

#define RCLCPP_INFO_STREAM(logger, stream_arg) \
   do { \
     static_assert( \
       ::std::is_same<typename std::remove_cv<typename std::remove_reference<decltype(logger)>::type>::type, \
       typename ::rclcpp::Logger>::value, \
       "First argument to logging macros must be an rclcpp::Logger"); \
  \
     std::stringstream ss; \
     ss << stream_arg; \
     RCUTILS_LOG_INFO_NAMED( \
       logger.get_name(), \
       "%s", rclcpp::get_c_string(ss.str())); \
   } while (0)

 #define RCLCPP_WARN_STREAM(logger, stream_arg) \
   do { \
     static_assert( \
       ::std::is_same<typename std::remove_cv<typename std::remove_reference<decltype(logger)>::type>::type, \
       typename ::rclcpp::Logger>::value, \
       "First argument to logging macros must be an rclcpp::Logger"); \
  \
     std::stringstream ss; \
     ss << stream_arg; \
     RCUTILS_LOG_WARN_NAMED( \
       logger.get_name(), \
       "%s", rclcpp::get_c_string(ss.str())); \
   } while (0)


#define RCLCPP_ERROR_STREAM(logger, stream_arg) \
   do { \
     static_assert( \
       ::std::is_same<typename std::remove_cv<typename std::remove_reference<decltype(logger)>::type>::type, \
       typename ::rclcpp::Logger>::value, \
       "First argument to logging macros must be an rclcpp::Logger"); \
  \
     std::stringstream ss; \
     ss << stream_arg; \
     RCUTILS_LOG_ERROR_NAMED( \
       logger.get_name(), \
       "%s", rclcpp::get_c_string(ss.str())); \
   } while (0)


// throttle defines

#define RCLCPP_WARN_THROTTLE(logger, clock, duration, ...) \
   do { \
     static_assert( \
       ::std::is_same<typename std::remove_cv<typename std::remove_reference<decltype(logger)>::type>::type, \
       typename ::rclcpp::Logger>::value, \
       "First argument to logging macros must be an rclcpp::Logger"); \
 \
     auto get_time_point = [&c=clock](rcutils_time_point_value_t * time_point) -> rcutils_ret_t { \
       try { \
         *time_point = c.now().nanoseconds(); \
       } catch (...) { \
         RCUTILS_SAFE_FWRITE_TO_STDERR( \
         "[rclcpp|logging.hpp] RCLCPP_WARN_THROTTLE could not get current time stamp\n"); \
         return RCUTILS_RET_ERROR; \
       } \
         return RCUTILS_RET_OK; \
     }; \
  \
     RCUTILS_LOG_WARN_THROTTLE_NAMED( \
       get_time_point, \
       duration, \
       logger.get_name(), \
       rclcpp::get_c_string(RCLCPP_FIRST_ARG(__VA_ARGS__, "")), \
         RCLCPP_ALL_BUT_FIRST_ARGS(__VA_ARGS__,"")); \
   } while (0)


#define RCLCPP_DEBUG_THROTTLE(logger, clock, duration, ...) \
   do { \
     static_assert( \
       ::std::is_same<typename std::remove_cv<typename std::remove_reference<decltype(logger)>::type>::type, \
       typename ::rclcpp::Logger>::value, \
       "First argument to logging macros must be an rclcpp::Logger"); \
 \
     auto get_time_point = [&c=clock](rcutils_time_point_value_t * time_point) -> rcutils_ret_t { \
       try { \
         *time_point = c.now().nanoseconds(); \
       } catch (...) { \
         RCUTILS_SAFE_FWRITE_TO_STDERR( \
         "[rclcpp|logging.hpp] RCLCPP_DEBUG_THROTTLE could not get current time stamp\n"); \
         return RCUTILS_RET_ERROR; \
       } \
         return RCUTILS_RET_OK; \
     }; \
  \
     RCUTILS_LOG_DEBUG_THROTTLE_NAMED( \
       get_time_point, \
       duration, \
       logger.get_name(), \
       rclcpp::get_c_string(RCLCPP_FIRST_ARG(__VA_ARGS__, "")), \
         RCLCPP_ALL_BUT_FIRST_ARGS(__VA_ARGS__,"")); \
   } while (0)
  

#define RCLCPP_ERROR_THROTTLE(logger, clock, duration, ...) \
   do { \
     static_assert( \
       ::std::is_same<typename std::remove_cv<typename std::remove_reference<decltype(logger)>::type>::type, \
       typename ::rclcpp::Logger>::value, \
       "First argument to logging macros must be an rclcpp::Logger"); \
 \
     auto get_time_point = [&c=clock](rcutils_time_point_value_t * time_point) -> rcutils_ret_t { \
       try { \
         *time_point = c.now().nanoseconds(); \
       } catch (...) { \
         RCUTILS_SAFE_FWRITE_TO_STDERR( \
         "[rclcpp|logging.hpp] RCLCPP_ERROR_THROTTLE could not get current time stamp\n"); \
         return RCUTILS_RET_ERROR; \
       } \
         return RCUTILS_RET_OK; \
     }; \
  \
     RCUTILS_LOG_ERROR_THROTTLE_NAMED( \
       get_time_point, \
       duration, \
       logger.get_name(), \
       rclcpp::get_c_string(RCLCPP_FIRST_ARG(__VA_ARGS__, "")), \
         RCLCPP_ALL_BUT_FIRST_ARGS(__VA_ARGS__,"")); \
   } while (0)