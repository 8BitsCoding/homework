#ifndef FFMPEG_H264_ENCODER_H
#define FFMPEG_H264_ENCODER_H

#include <cstdint>
#include <mutex>
#include "av_encoder.h"

namespace ffmpeg {

class H264Encoder : public Encoder
{
public:
	virtual bool Init(AVConfig& video_config);
	virtual void Destroy();

	AVPacketPtr Encode(const uint8_t *image, uint32_t width, uint32_t height, uint64_t pts = 0);
	void setFormatC(AVFormatContext* _p) { pFormatC = _p; }
	void setMutex(std::mutex* _mtx) { mtx = _mtx; }
private:
	SwsContext* sws_contex_ = nullptr;
	AVFrame* yuv_frame_ = nullptr;
	uint32_t  pts_ = 0;
	AVFormatContext* pFormatC = nullptr;
	std::mutex* mtx;
};

}

#endif
