#pragma once

#include <ismrmrd/ismrmrd.h>
#include <ismrmrd/meta.h>
#include <ismrmrd/waveform.h>

#include <boost/optional.hpp>
#include <boost/variant.hpp>
#include <tuple>

#include "hoNDArray.h"
#include "TypeTraits.h"

namespace Gadgetron::Core {
    template<class T>
    using optional = boost::optional<T>;
    static const auto none = boost::none;

    template<class... ARGS>
    using variant = boost::variant<ARGS...>;
    using boost::apply_visitor;

    template<class... ARGS>
    using tuple = std::tuple<ARGS...>;

/// An Acquisition consists of a data header, the kspace data itself and optionally an array of kspace trajectories
    using Acquisition = tuple<ISMRMRD::AcquisitionHeader,  hoNDArray<std::complex<float>>,optional<hoNDArray<float>>>;

/// A Waveform consiste of a header, followed by the raw Waveform data. See the MRD documentation page for more details
    using Waveform    = tuple<ISMRMRD::WaveformHeader, hoNDArray<uint32_t>>;

    ///An image consists of a header, an array of image data and optionally some metadata
    template<class T>
    using Image = tuple<ISMRMRD::ImageHeader,  hoNDArray<T>, optional<ISMRMRD::MetaContainer>>;
}


#include "Types.hpp"