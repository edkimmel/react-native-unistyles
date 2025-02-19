///
/// ColorScheme.hpp
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2025 Marc Rousavy @ Margelo
///

#pragma once

#if __has_include(<NitroModules/NitroHash.hpp>)
#include <NitroModules/NitroHash.hpp>
#else
#error NitroModules cannot be found! Are you sure you installed NitroModules properly?
#endif
#if __has_include(<NitroModules/JSIConverter.hpp>)
#include <NitroModules/JSIConverter.hpp>
#else
#error NitroModules cannot be found! Are you sure you installed NitroModules properly?
#endif
#if __has_include(<NitroModules/NitroDefines.hpp>)
#include <NitroModules/NitroDefines.hpp>
#else
#error NitroModules cannot be found! Are you sure you installed NitroModules properly?
#endif

namespace margelo::nitro::unistyles {

  /**
   * An enum which can be represented as a JavaScript union (ColorScheme).
   */
  enum class ColorScheme {
    DARK      SWIFT_NAME(dark) = 0,
    LIGHT      SWIFT_NAME(light) = 1,
    UNSPECIFIED      SWIFT_NAME(unspecified) = 2,
  } CLOSED_ENUM;

} // namespace margelo::nitro::unistyles

namespace margelo::nitro {

  using namespace margelo::nitro::unistyles;

  // C++ ColorScheme <> JS ColorScheme (union)
  template <>
  struct JSIConverter<ColorScheme> {
    static inline ColorScheme fromJSI(jsi::Runtime& runtime, const jsi::Value& arg) {
      std::string unionValue = JSIConverter<std::string>::fromJSI(runtime, arg);
      switch (hashString(unionValue.c_str(), unionValue.size())) {
        case hashString("dark"): return ColorScheme::DARK;
        case hashString("light"): return ColorScheme::LIGHT;
        case hashString("unspecified"): return ColorScheme::UNSPECIFIED;
        default: [[unlikely]]
          throw std::invalid_argument("Cannot convert \"" + unionValue + "\" to enum ColorScheme - invalid value!");
      }
    }
    static inline jsi::Value toJSI(jsi::Runtime& runtime, ColorScheme arg) {
      switch (arg) {
        case ColorScheme::DARK: return JSIConverter<std::string>::toJSI(runtime, "dark");
        case ColorScheme::LIGHT: return JSIConverter<std::string>::toJSI(runtime, "light");
        case ColorScheme::UNSPECIFIED: return JSIConverter<std::string>::toJSI(runtime, "unspecified");
        default: [[unlikely]]
          throw std::invalid_argument("Cannot convert ColorScheme to JS - invalid value: "
                                    + std::to_string(static_cast<int>(arg)) + "!");
      }
    }
    static inline bool canConvert(jsi::Runtime& runtime, const jsi::Value& value) {
      if (!value.isString()) {
        return false;
      }
      std::string unionValue = JSIConverter<std::string>::fromJSI(runtime, value);
      switch (hashString(unionValue.c_str(), unionValue.size())) {
        case hashString("dark"):
        case hashString("light"):
        case hashString("unspecified"):
          return true;
        default:
          return false;
      }
    }
  };

} // namespace margelo::nitro
