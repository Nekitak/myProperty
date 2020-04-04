#pragma once

#include "../definitions.h"

namespace Net
{

    /// @todo
    template<typename Type , typename Owner>
    class Property
    {
        protected:
            typedef Type(Owner::*getter)();
            typedef void(Owner::*setter)();
            Owner*  owner;
            getter  get;
            setter  set;

        public:
            Property ()
                : owner(NULL) , get(NULL) , set(NULL)
            { }

            ~Property ( )
            {

            }



            void init(Owner*  owner , getter getmethod  )
            {
                this->owner = owner;
                this->get = getmethod;
            }

            void init(Owner*  owner , getter getmethod , setter setmethod)
            {
                this->owner = owner;
                this->get = getmethod;
                this->set = setmethod;
            }

            operator Type()
            {
                return (owner->*get)();
            }

            void operator =(Type data)
            {
                (owner->set)(data);
            }


    };

}
