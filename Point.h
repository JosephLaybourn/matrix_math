////////////////////////////////////////////////////////////////////////////////
#ifndef POINT_H
#define POINT_H
////////////////////////////////////////////////////////////////////////////////

#include <iostream> // istream, ostream

namespace CS170
{
  class Point //!< a 2D point with x and y values and vector math
  {
    public:
      // Constructors (2)

      //! gives in the x and y values
      Point(double x, double y);

      //! default constructor, sets x and y to 0
      Point();

      // Overloaded operators (14 member functions)
        
      //! Rotates a Point about the origin the specified number of degrees.
      Point operator%(double degrees) const;
        
      //! Calculates the difference between two Points and returns the distance
      double operator-(Point rhs) const;
      
      //! Calculates the midpoint of two Points. Returns a new Point. 
      Point operator^(Point rhs) const;
      
      /*! Adds two Points and returns a reference to
          the left-hand operand which has been modified */
      Point &operator+=(Point rhs);
        
      /*! Adds a Point and a double and returns a reference 
          to the left-hand operand which has been modified  */
      Point &operator+=(double scale);
      
      //! Subtracts a double from a Point and returns a new Point
      Point operator-(double scale) const;
      
      //! Adds one to the x/y values of the object *PRE-INCREMENT*
      Point &operator++();
      
      //! Adds one to the x/y values of the object *POST-INCREMENT*
      Point operator++(int);
      
      //! Subtracts one to the x/y values of the object *PRE-INCREMENT*
      Point &operator--();
      
      //! Subtracts one to the x/y values of the object *POST-INCREMENT*
      Point operator--(int);
      
      //! Returns a new Point that has the x/y values of the input Point negated
      Point operator-() const;
      
      //! Adds two Points and returns a new Point.
      Point operator+(Point rhs) const;

      //! Adds a Point and a double and returns a new Point. 
      Point operator+(double scale) const;
      
      //! Multiplies a Point by some numeric factor and returns a new Point
      Point operator*(double scale) const;

      
      // Overloaded operators (2 friend functions)

      //! Inputs a Point. Allows 2 numbers to be entered
      friend std::istream &operator>>(std::istream &is, Point &rhs);

      //! Outputs a Point in the form of a string: (x, y)
      friend std::ostream &operator<<(std::ostream &os, const Point rhs);

    private:
      double x_; //!< The x-coordinate of a Point
      double y_; //!< The y-coordinate of a Point

        // Helper functions
      //! converts degrees to radians
      double DegreesToRadians(double degrees) const;
      
      //! converts radians to degrees
      double RadiansToDegrees(double radians) const;
  };
  
  // Overloaded operators (2 non-member, non-friend functions)

  //! Non member version of the translation operator
  Point operator+(double scale, Point rhs);
    
  //! non member version of the scale operator
  Point operator*(double scale, Point rhs);

} // namespace CS170

#endif
////////////////////////////////////////////////////////////////////////////////
