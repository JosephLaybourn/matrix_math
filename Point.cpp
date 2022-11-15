/******************************************************************************/
/*!
\file   Point.cpp
\author Joey Laybourn
\par    email: j.laybourn\@digipen.edu
\par    DigiPen login: j.laybourn
\par    Course: CS170
\par    Section: B
\par    Assignment 3
\date   3/1/2018
\brief  
    This file contains overloaded operators to do vector math
      
    Functions include:
    
       + operator%
       + operator-(binary)
       + operator^
       + operator+=(Point)
       + operator+=(double)
       + operator-(unary)
       + operator++(pre-fix)
       + operator++(post-fix)
       + operator--(pre-fix)
       + operator--(post-fix)
       + operator-(unary)
       + operator+(Point)
       + operator+(double)
       + operator+(non-member)
       + operator*
       + operator*(non-member)
       + operator<<
       + operator>>
    
  Hours spent on this assignment: 3

  Specific portions that gave you the most trouble: writing all the functions
*/
/******************************************************************************/

#include "Point.h"  // Point members
#include <cmath>    // sqrt, atan, sin, cos

namespace CS170
{

  const double PI = 3.1415926535897; //!< pi approximation
  const double EPSILON = 0.00001;    //!< epsilon value

  /////////////////////////////////////////////////////////////////////////////
  // private member functions 
  double Point::DegreesToRadians(double degrees) const
  {
    // formula to return the radians into degrees
    return (degrees * PI / 180.0);
  }

  double Point::RadiansToDegrees(double radians) const
  {
    // formualt to return radians into degrees
    return (radians * 180.0 / PI);
  }


  /////////////////////////////////////////////////////////////////////////////
  // 16 public member functions (2 constructors, 14 operators) 

  /****************************************************************************/
  /*!
   \brief 
   constructs a point with x and y coordinates as arguments
   
   \param x
   x coordinate
   
   \param y
   y coordinate
  */
  /****************************************************************************/
  Point::Point(double x, double y)
  {
    x_ = x; // initializes x
    y_ = y; // initializes y
  }

/****************************************************************************/
  /*!
   \brief 
   constructs a point with x and y coordinates set to 0
  */
  /****************************************************************************/
  Point::Point()
  {
    x_ = 0; // initializes x to 0
    y_ = 0; // initializes y to 0
  }

  /****************************************************************************/
  /*!
   \brief 
   rotates a point over the origin
   
   \param degrees
   angle in degrees the point is rotated
   
   \return Point
  */
  /****************************************************************************/
  Point Point::operator%(double degrees) const
  {
    // sin of the angle argument
    double sinRot = sin(DegreesToRadians(degrees));
    
    //cosine of the angle argument
    double cosRot = cos(DegreesToRadians(degrees));
    
    // the x point through a "rotation matrix"
    double xResult = (cosRot * x_) + (-sinRot * y_);
    
    // the y point through a "rotation matrix"
    double yResult = (sinRot * x_) + (cosRot * y_);
    
    // makes sure the x sign bit is 0 if the value is close to 0
    if(xResult >= -EPSILON && xResult <= EPSILON)
    {
      xResult = 0;
    }
    
    // makes sure the y sign bit is 0 if the value is close to 0
    if(yResult >= -EPSILON && yResult <= EPSILON)
    {
      yResult = 0;
    }
    
    //returns rotates point
    return Point(xResult, yResult);
  }

  /****************************************************************************/
  /*!
   \brief 
   calculates the distance between 2 points
   
   \param rhs
   point the class is being subtracted by
   
   \return Point
  */
  /****************************************************************************/
  double Point::operator-(Point rhs) const
  {

    double xSub = x_ - rhs.x_; // subtracts the 2 x values
    double ySub = y_ - rhs.y_; // subtracts the 2 y values

    // gets the squared distance
    double distSquared = (xSub * xSub) + (ySub * ySub);

    //returns the square root of the squared distance
    return sqrt(distSquared);
  }

  /****************************************************************************/
  /*!
   \brief 
   calculates the midpoint
   
   \param rhs
   Point the class is being calculated the midpoint by
   
   \return Point
  */
  /****************************************************************************/
  Point Point::operator^(Point rhs) const
  {
    double midX = (x_ + rhs.x_) / 2; // calculates the midpoint of x
    double midY = (y_ + rhs.y_) / 2; // calculates the midpoint of y

    return Point(midX, midY); // returns the new point containing the midpoints
  }

  /****************************************************************************/
  /*!
   \brief 
   adds 2 points together
   
   \param rhs
   Point the class is being added to
   
   \return Point
  */
  /****************************************************************************/
  Point &Point::operator+=(Point rhs)
  {
    x_ += rhs.x_; // adds the 2 x values together
    y_ += rhs.y_; // adds the 2 y values together

    return *this; // returns this class
  }

  /****************************************************************************/
  /*!
   \brief 
   adds the point by a number
   
   \param scale
   number each point is being added by
   
   \return Point
  */
  /****************************************************************************/
  Point &Point::operator+=(double scale)
  {
    x_ += scale;  // adds the x point by the scale
    y_ += scale;  // adds the y point by the scale

    return *this; // returns this class
  }

  /****************************************************************************/
  /*!
   \brief 
   subtracts a point by a number
   
   \param scale
   amount the point is being subtracted by
   
   \return Point
  */
  /****************************************************************************/
  Point Point::operator-(double scale) const
  {
    double xResult = x_ - scale;    // subtracts x value by a scale
    double yResult = y_ - scale;    // subtracts y value by a scale

    return Point(xResult, yResult); // returns a point with updates values
  }
  
  /****************************************************************************/
  /*!
   \brief 
   incremets the point by 1
   
   \return Point
  */
  /****************************************************************************/
  Point &Point::operator++()
  {
    x_++;         // increments x by 1
    y_++;         // increments y by 1
    
    return *this; // returns this class
  }
  
  /****************************************************************************/
  /*!
   \brief 
   increments the point by 1 and returns the value of the point before increment
   
   \return Point
  */
  /****************************************************************************/
  Point Point::operator++(int)
  {
    double x = x_;      // used for storing the x before incrementing
    double y = y_;      // used for storing the y before incrementing
    x_++;               // increments x by 1
    y_++;               // increments y by 1 
    
    return Point(x, y); // returns a point with values before incrementing
  }
  
  /****************************************************************************/
  /*!
   \brief 
   decrements the point by 1 
   
   \return Point
  */
  /****************************************************************************/
  Point &Point::operator--()
  {
    x_--;         // decrements x by 1
    y_--;         // decrements y by 1
    
    return *this; // returns this class
  }

  /****************************************************************************/
  /*!
   \brief 
   decrements the point by 1 and returns the value of the point before decrement
   
   \return Point
  */
  /****************************************************************************/
  Point Point::operator--(int)
  {
    double x = x_;      // saves the x value before decrementing
    double y = y_;      // saves the y value before decrementing
    x_--;               // decrements x by 1
    y_--;               // decrements y by 1
    
    return Point(x, y); // returns the point before decrementing
  }
  
  /****************************************************************************/
  /*!
   \brief 
   returns the opposite of the class
   
   \return Point
  */
  /****************************************************************************/
  Point Point::operator-() const
  {
    double xResult = -x_;           // the opposite of the current x value
    double yResult = -y_;           // the opposite of the current y value
    
    return Point(xResult, yResult); // returns the opposite of the class
  }

  /****************************************************************************/
  /*!
   \brief 
   adds two points together
   
   \param rhs
   the point being added
   
   \return Point
  */
  /****************************************************************************/
  Point Point::operator+(Point rhs) const 
  {
    double xResult = x_ + rhs.x_;   // adds both x values together
    double yResult = y_ + rhs.y_;   // adds both y values together

    return Point(xResult, yResult); // returns a point with both points added
  }
  
  /****************************************************************************/
  /*!
   \brief 
   increments the point by 1 and returns the value of the point before increment
   
   \param scale
   the amount x and y are being added by
   
   \return Point
  */
  /****************************************************************************/
  Point Point::operator+(double scale) const
  {
    double xResult = x_ + scale;    // adds x by a scale
    double yResult = y_ + scale;    // adds y by a scale

    return Point(xResult, yResult); // returns the point with the added values
  }

  /****************************************************************************/
  /*!
   \brief 
   scales a point
   
   \param scale
   the amount the point is being scaled by
   
   \return Point
  */
  /****************************************************************************/
  Point Point::operator*(double scale) const
  {
    double xResult = x_ * scale;    // scales the x value
    double yResult = y_ * scale;    // scales the y value

    return Point(xResult, yResult); // returns the scales point
  }


  /////////////////////////////////////////////////////////////////////////////
  // 2 friend functions (operators)

  /****************************************************************************/
  /*!
   \brief 
   gets data by the user(x space y) and parses it into x and y
   
   \param is
   the input stream
   
   \param rhs
   the point being updated
   
   \return istream
  */
  /****************************************************************************/
  std::istream &operator>>(std::istream &is, Point &rhs)
  {
    is >> rhs.x_ >> rhs.y_; // parses user input into a point
    
    return is;              // returns the input stream
  }

  /****************************************************************************/
  /*!
   \brief 
   outputs the coordinate like (x, y)
   
   \param os
   the outputs stream
   
   \param rhs
   the point containing the values to print out
   
   \return ostream
  */
  /****************************************************************************/
  std::ostream &operator<<(std::ostream &os, const Point rhs)
  {
    // prints the x and y values in a standard mathematical format
    os << "(" << rhs.x_ << ", " << rhs.y_ << ")";
    
    return os; // returns the output stream
  }

  /////////////////////////////////////////////////////////////////////////////
  // 2 non-members, non-friends (operators)

  /****************************************************************************/
  /*!
   \brief 
   scales a point
   
   \param scale
   the amount the point is being scaled by
   
   \param rhs
   point being scaled
   
   \return Point
  */
  /****************************************************************************/
  Point operator*(double scale, Point rhs)
  {
    Point result = rhs * scale; // scales the point using the member function

    return result;              // returns the scaled point
  }

  /****************************************************************************/
  /*!
   \brief 
   adds a point by a number
   
   \param scale
   the amount to add to x and y
   
   \param rhs
   the point being added to
   
   \return Point
  */
  /****************************************************************************/
  Point operator+(double scale, Point rhs)
  {
    Point result = rhs + scale; // adds the point by a number

    return result;              // returns the added point
  }
} // namespace CS170
