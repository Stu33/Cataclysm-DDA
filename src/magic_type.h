#pragma once
#ifndef CATA_SRC_MAGIC_TYPE_H
#define CATA_SRC_MAGIC_TYPE_H\


#include <optional>
#include <vector>

#include "enum_bitset.h"
#include "type_id.h"

class magic_type
{
    public:

        magic_type() = default;

        bool was_loaded = false;

        magic_type_id id;

        mod_id src_mod;
        
        static void load_magic_type( const JsonObject &jo, const std::string &src );
        void load( const JsonObject &jo, std::string_view src );
        void serialize( JsonOut &json ) const;

        // these two formulas should be the inverse of eachother.  The spell xp will break if this is not the case.
        std::optional<jmath_func_id> get_level_formula_id;
        std::optional<jmath_func_id> exp_for_level_formula_id;

        static const std::vector<magic_type> &get_all();
        static void check_consistency();
    private:

};

#endif // CATA_SRC_MAGIC_TYPE_H