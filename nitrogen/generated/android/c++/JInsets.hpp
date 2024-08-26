///
/// JInsets.hpp
/// Mon Aug 26 2024
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/react-native-nitro
/// Copyright © 2024 Marc Rousavy @ Margelo
///

#pragma once

#include <fbjni/fbjni.h>
#include "Insets.hpp"

namespace margelo::nitro::unistyles {

  using namespace facebook;

  /**
   * The C++ JNI bridge between the C++ struct "Insets" and the the Kotlin data class "Insets".
   */
  struct JInsets: public jni::JavaClass<JInsets> {
  public:
    static auto constexpr kJavaDescriptor = "Lcom/margelo/nitro/unistyles/Insets;";

  public:
    /**
     * Convert this Java/Kotlin-based struct to the C++ struct Insets by copying all values to C++.
     */
    Insets toInsets() {
      static const auto clazz = javaClassStatic();
      static const auto fieldTop = clazz->getField<double>("top");
      double top = this->getFieldValue(fieldTop);
      static const auto fieldBottom = clazz->getField<double>("bottom");
      double bottom = this->getFieldValue(fieldBottom);
      static const auto fieldLeft = clazz->getField<double>("left");
      double left = this->getFieldValue(fieldLeft);
      static const auto fieldRight = clazz->getField<double>("right");
      double right = this->getFieldValue(fieldRight);
      static const auto fieldIme = clazz->getField<double>("ime");
      double ime = this->getFieldValue(fieldIme);
      return Insets(
        top,
        bottom,
        left,
        right,
        ime
      );
    }

  public:
    /**
     * Create a Java/Kotlin-based struct by copying all values from the given C++ struct to Java.
     */
    static jni::local_ref<JInsets::javaobject> create(const Insets& value) {
      return newInstance(
        value.top,
        value.bottom,
        value.left,
        value.right,
        value.ime
      );
    }
  };

} // namespace margelo::nitro::unistyles
