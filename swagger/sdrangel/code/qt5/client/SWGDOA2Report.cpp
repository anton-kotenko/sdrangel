/**
 * SDRangel
 * This is the web REST/JSON API of SDRangel SDR software. SDRangel is an Open Source Qt5/OpenGL 3.0+ (4.3+ in Windows) GUI and server Software Defined Radio and signal analyzer in software. It supports Airspy, BladeRF, HackRF, LimeSDR, PlutoSDR, RTL-SDR, SDRplay RSP1 and FunCube    ---   Limitations and specifcities:    * In SDRangel GUI the first Rx device set cannot be deleted. Conversely the server starts with no device sets and its number of device sets can be reduced to zero by as many calls as necessary to /sdrangel/deviceset with DELETE method.   * Preset import and export from/to file is a server only feature.   * Device set focus is a GUI only feature.   * The following channels are not implemented (status 501 is returned): ATV and DATV demodulators, Channel Analyzer NG, LoRa demodulator   * The device settings and report structures contains only the sub-structure corresponding to the device type. The DeviceSettings and DeviceReport structures documented here shows all of them but only one will be or should be present at a time   * The channel settings and report structures contains only the sub-structure corresponding to the channel type. The ChannelSettings and ChannelReport structures documented here shows all of them but only one will be or should be present at a time    --- 
 *
 * OpenAPI spec version: 7.0.0
 * Contact: f4exb06@gmail.com
 *
 * NOTE: This class is auto generated by the swagger code generator program.
 * https://github.com/swagger-api/swagger-codegen.git
 * Do not edit the class manually.
 */


#include "SWGDOA2Report.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace SWGSDRangel {

SWGDOA2Report::SWGDOA2Report(QString* json) {
    init();
    this->fromJson(*json);
}

SWGDOA2Report::SWGDOA2Report() {
    phi = 0;
    m_phi_isSet = false;
    pos_az = 0;
    m_pos_az_isSet = false;
    neg_az = 0;
    m_neg_az_isSet = false;
    fft_size = 0;
    m_fft_size_isSet = false;
    channel_sample_rate = 0;
    m_channel_sample_rate_isSet = false;
}

SWGDOA2Report::~SWGDOA2Report() {
    this->cleanup();
}

void
SWGDOA2Report::init() {
    phi = 0;
    m_phi_isSet = false;
    pos_az = 0;
    m_pos_az_isSet = false;
    neg_az = 0;
    m_neg_az_isSet = false;
    fft_size = 0;
    m_fft_size_isSet = false;
    channel_sample_rate = 0;
    m_channel_sample_rate_isSet = false;
}

void
SWGDOA2Report::cleanup() {





}

SWGDOA2Report*
SWGDOA2Report::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGDOA2Report::fromJsonObject(QJsonObject &pJson) {
    ::SWGSDRangel::setValue(&phi, pJson["phi"], "qint32", "");
    
    ::SWGSDRangel::setValue(&pos_az, pJson["posAz"], "qint32", "");
    
    ::SWGSDRangel::setValue(&neg_az, pJson["negAz"], "qint32", "");
    
    ::SWGSDRangel::setValue(&fft_size, pJson["fftSize"], "qint32", "");
    
    ::SWGSDRangel::setValue(&channel_sample_rate, pJson["channelSampleRate"], "qint32", "");
    
}

QString
SWGDOA2Report::asJson ()
{
    QJsonObject* obj = this->asJsonObject();

    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    delete obj;
    return QString(bytes);
}

QJsonObject*
SWGDOA2Report::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    if(m_phi_isSet){
        obj->insert("phi", QJsonValue(phi));
    }
    if(m_pos_az_isSet){
        obj->insert("posAz", QJsonValue(pos_az));
    }
    if(m_neg_az_isSet){
        obj->insert("negAz", QJsonValue(neg_az));
    }
    if(m_fft_size_isSet){
        obj->insert("fftSize", QJsonValue(fft_size));
    }
    if(m_channel_sample_rate_isSet){
        obj->insert("channelSampleRate", QJsonValue(channel_sample_rate));
    }

    return obj;
}

qint32
SWGDOA2Report::getPhi() {
    return phi;
}
void
SWGDOA2Report::setPhi(qint32 phi) {
    this->phi = phi;
    this->m_phi_isSet = true;
}

qint32
SWGDOA2Report::getPosAz() {
    return pos_az;
}
void
SWGDOA2Report::setPosAz(qint32 pos_az) {
    this->pos_az = pos_az;
    this->m_pos_az_isSet = true;
}

qint32
SWGDOA2Report::getNegAz() {
    return neg_az;
}
void
SWGDOA2Report::setNegAz(qint32 neg_az) {
    this->neg_az = neg_az;
    this->m_neg_az_isSet = true;
}

qint32
SWGDOA2Report::getFftSize() {
    return fft_size;
}
void
SWGDOA2Report::setFftSize(qint32 fft_size) {
    this->fft_size = fft_size;
    this->m_fft_size_isSet = true;
}

qint32
SWGDOA2Report::getChannelSampleRate() {
    return channel_sample_rate;
}
void
SWGDOA2Report::setChannelSampleRate(qint32 channel_sample_rate) {
    this->channel_sample_rate = channel_sample_rate;
    this->m_channel_sample_rate_isSet = true;
}


bool
SWGDOA2Report::isSet(){
    bool isObjectUpdated = false;
    do{
        if(m_phi_isSet){
            isObjectUpdated = true; break;
        }
        if(m_pos_az_isSet){
            isObjectUpdated = true; break;
        }
        if(m_neg_az_isSet){
            isObjectUpdated = true; break;
        }
        if(m_fft_size_isSet){
            isObjectUpdated = true; break;
        }
        if(m_channel_sample_rate_isSet){
            isObjectUpdated = true; break;
        }
    }while(false);
    return isObjectUpdated;
}
}

