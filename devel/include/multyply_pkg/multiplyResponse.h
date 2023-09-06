// Generated by gencpp from file multyply_pkg/multiplyResponse.msg
// DO NOT EDIT!


#ifndef MULTYPLY_PKG_MESSAGE_MULTIPLYRESPONSE_H
#define MULTYPLY_PKG_MESSAGE_MULTIPLYRESPONSE_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace multyply_pkg
{
template <class ContainerAllocator>
struct multiplyResponse_
{
  typedef multiplyResponse_<ContainerAllocator> Type;

  multiplyResponse_()
    : c(0.0)  {
    }
  multiplyResponse_(const ContainerAllocator& _alloc)
    : c(0.0)  {
  (void)_alloc;
    }



   typedef double _c_type;
  _c_type c;





  typedef boost::shared_ptr< ::multyply_pkg::multiplyResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::multyply_pkg::multiplyResponse_<ContainerAllocator> const> ConstPtr;

}; // struct multiplyResponse_

typedef ::multyply_pkg::multiplyResponse_<std::allocator<void> > multiplyResponse;

typedef boost::shared_ptr< ::multyply_pkg::multiplyResponse > multiplyResponsePtr;
typedef boost::shared_ptr< ::multyply_pkg::multiplyResponse const> multiplyResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::multyply_pkg::multiplyResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::multyply_pkg::multiplyResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::multyply_pkg::multiplyResponse_<ContainerAllocator1> & lhs, const ::multyply_pkg::multiplyResponse_<ContainerAllocator2> & rhs)
{
  return lhs.c == rhs.c;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::multyply_pkg::multiplyResponse_<ContainerAllocator1> & lhs, const ::multyply_pkg::multiplyResponse_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace multyply_pkg

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::multyply_pkg::multiplyResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::multyply_pkg::multiplyResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::multyply_pkg::multiplyResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::multyply_pkg::multiplyResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::multyply_pkg::multiplyResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::multyply_pkg::multiplyResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::multyply_pkg::multiplyResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "37953dcb2c8b50ce9a4540c4b1b72908";
  }

  static const char* value(const ::multyply_pkg::multiplyResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x37953dcb2c8b50ceULL;
  static const uint64_t static_value2 = 0x9a4540c4b1b72908ULL;
};

template<class ContainerAllocator>
struct DataType< ::multyply_pkg::multiplyResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "multyply_pkg/multiplyResponse";
  }

  static const char* value(const ::multyply_pkg::multiplyResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::multyply_pkg::multiplyResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float64 c\n"
;
  }

  static const char* value(const ::multyply_pkg::multiplyResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::multyply_pkg::multiplyResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.c);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct multiplyResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::multyply_pkg::multiplyResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::multyply_pkg::multiplyResponse_<ContainerAllocator>& v)
  {
    s << indent << "c: ";
    Printer<double>::stream(s, indent + "  ", v.c);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MULTYPLY_PKG_MESSAGE_MULTIPLYRESPONSE_H
