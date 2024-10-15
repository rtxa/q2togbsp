#pragma once

#include <string>

#include "math/Vector3f.h"

class QuakeFace {
   public:
    void setOffsetX(float value);
    void setOffsetY(float value);
    void setRotation(float value);
    void setScaleX(float value);
    void setScaleY(float value);
    void setPlane(Vector3f point1, Vector3f point2, Vector3f point3);
    void setTextureName(const std::string& name);
    void setContentFlags(int flags);
    void setSurfaceFlags(int flags);
    void setLightIntensity(int value);
    void setTransparencyValue(int value);
    void setReflectivityScale(float value);
    void setXLightMapScale(float value);
    void setYLightMapScale(float value);
    void setMipMapBias(float value);

    float getOffsetX() const;
    float getOffsetY() const;
    float getRotation() const;
    float getScaleX() const;
    float getScaleY() const;
    Vector3f getPlane(int index) const;
    std::string getTextureName() const;
    int getContentFlags() const;
    int getSurfaceFlags() const;
    int getLightIntensity() const;
    int getTransparencyValue() const;
    float getReflectivityScale() const;
    float getXLightMapScale() const;
    float getYLightMapScale() const;
    float getMipMapBias() const;

    std::string toString() const;

    Vector3f getVecU() const;
    void setVecU(const Vector3f &uVec);

    Vector3f getVecV() const;
    void setVecV(const Vector3f &vVec);

    bool isValveFormat() const;
    void setValveFormat(bool isValveFormat);

   private:
    // plane
    Vector3f m_point1;
    Vector3f m_point2;
    Vector3f m_point3;
    std::string m_textureName;  // TODO: use char[32] or std::array
    float m_xOffset{0.0f};
    float m_yOffset{0.0f};
    Vector3f m_uVec; // Used by Valve format
    Vector3f m_vVec; // Used by Valve format
    float m_rotation{0.0f};
    float m_xScale{0.0f};
    float m_yScale{0.0f};
    int m_contentFlags{0};
    int m_surfaceFlags{0};
    int m_lightIntensity{0};
    int m_transparencyValue{255};
    float m_reflectivityScale{1.0f};
    float m_xLightMapScale{1.0f};
    float m_yLightMapScale{1.0f};
    float m_mipMapBias{1.0f};
    bool m_isValveFormat{false};
};
