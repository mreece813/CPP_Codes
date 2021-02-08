#pragma once

#include <cstdlib>
#include <string>

namespace ruc_sci_comp
{
static bool disable_for_test()
{
    static const char *DISABLE_MALEN = getenv("DISABLE_MALEN");
    std::string flag = DISABLE_MALEN == nullptr ? "ENABLE" : DISABLE_MALEN;
    return flag.empty();
}
}
