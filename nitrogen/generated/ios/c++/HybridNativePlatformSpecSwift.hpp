///
/// HybridNativePlatformSpecSwift.hpp
/// Sun Aug 18 2024
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/react-native-nitro
/// Copyright © 2024 Marc Rousavy @ Margelo
///

#pragma once

#include "HybridNativePlatformSpec.hpp"

// Forward declaration of `HybridNativePlatformSpecCxx` to properly resolve imports.
namespace Unistyles { class HybridNativePlatformSpecCxx; }

// Forward declaration of `Insets` to properly resolve imports.
namespace margelo::nitro::unistyles { struct Insets; }
// Forward declaration of `ColorScheme` to properly resolve imports.
namespace margelo::nitro::unistyles { enum class ColorScheme; }
// Forward declaration of `Dimensions` to properly resolve imports.
namespace margelo::nitro::unistyles { struct Dimensions; }

#include "Insets.hpp"
#include "ColorScheme.hpp"
#include <string>
#include "Dimensions.hpp"
#include <optional>

#if __has_include(<NitroModules/HybridContext.hpp>)
#include <NitroModules/HybridContext.hpp>
#else
#error NitroModules cannot be found! Are you sure you installed NitroModules properly?
#endif

#include "Unistyles-Swift-Cxx-Umbrella.hpp"

namespace margelo::nitro::unistyles {

  /**
   * The C++ part of HybridNativePlatformSpecCxx.swift.
   *
   * HybridNativePlatformSpecSwift (C++) accesses HybridNativePlatformSpecCxx (Swift), and might
   * contain some additional bridging code for C++ <> Swift interop.
   *
   * Since this obviously introduces an overhead, I hope at some point in
   * the future, HybridNativePlatformSpecCxx can directly inherit from the C++ class HybridNativePlatformSpec
   * to simplify the whole structure and memory management.
   */
  class HybridNativePlatformSpecSwift final: public HybridNativePlatformSpec {
  public:
    // Constructor from a Swift instance
    explicit HybridNativePlatformSpecSwift(const Unistyles::HybridNativePlatformSpecCxx& swiftPart): HybridNativePlatformSpec(), _swiftPart(swiftPart) { }

  public:
    // Get the Swift part
    inline Unistyles::HybridNativePlatformSpecCxx getSwiftPart() noexcept { return _swiftPart; }

  public:
    // Get memory pressure
    inline size_t getExternalMemorySize() noexcept override {
      return _swiftPart.getMemorySize();
    }

  public:
    // Properties
    

  public:
    // Methods
    inline Insets getInsets() override {
      auto value = _swiftPart.getInsets();
      return value;
    }
    inline ColorScheme getColorScheme() override {
      auto value = _swiftPart.getColorScheme();
      return static_cast<ColorScheme>(value);
    }
    inline double getFontScale() override {
      auto value = _swiftPart.getFontScale();
      return value;
    }
    inline double getPixelRatio() override {
      auto value = _swiftPart.getPixelRatio();
      return value;
    }
    inline std::string getContentSizeCategory() override {
      auto value = _swiftPart.getContentSizeCategory();
      return value;
    }
    inline Dimensions getScreenDimensions() override {
      auto value = _swiftPart.getScreenDimensions();
      return value;
    }
    inline Dimensions getStatusBarDimensions() override {
      auto value = _swiftPart.getStatusBarDimensions();
      return value;
    }
    inline bool getPrefersRtlDirection() override {
      auto value = _swiftPart.getPrefersRtlDirection();
      return value;
    }
    inline void setRootViewBackgroundColor(const std::optional<std::string>& hex, std::optional<double> alpha) override {
      _swiftPart.setRootViewBackgroundColor(hex, alpha);
    }
    inline void setNavigationBarBackgroundColor(const std::optional<std::string>& hex, std::optional<double> alpha) override {
      _swiftPart.setNavigationBarBackgroundColor(hex, alpha);
    }
    inline void setNavigationBarHidden(bool isHidden) override {
      _swiftPart.setNavigationBarHidden(std::forward<decltype(isHidden)>(isHidden));
    }
    inline void setStatusBarBackgroundColor(const std::optional<std::string>& hex, std::optional<double> alpha) override {
      _swiftPart.setStatusBarBackgroundColor(hex, alpha);
    }
    inline void setImmersiveMode(bool isEnabled) override {
      _swiftPart.setImmersiveMode(std::forward<decltype(isEnabled)>(isEnabled));
    }

  private:
    Unistyles::HybridNativePlatformSpecCxx _swiftPart;
  };

} // namespace margelo::nitro::unistyles
