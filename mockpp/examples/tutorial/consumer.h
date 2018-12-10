/***************************************************************************
          consumer.h  -  configuration consumer class

                             -------------------
    begin                : Sun 2 Jan 2005
    copyright            : (C) 2002-2010 by Ewald Arnold
    email                : mockpp at ewald-arnold dot de

  $Id: consumer.h 1491 2010-01-02 22:21:45Z ewald-arnold $

 ***************************************************************************/


#include <string>


class Interface;

class Consumer
{
  public:

    /** Constructs the consumer class.
      * @param  intf  pointer to interface object
      */
    Consumer(Interface *intf);

    /** Loads all records from the file
      */
    void load();

    /** Processes all records
      */
    void process();

    /** Stores all records into file
      */
    void save();

  private:

    Interface   *configfile;
    MOCKPP_STL::string  config1;
    MOCKPP_STL::string  config2;
    MOCKPP_STL::string  config3;
};

