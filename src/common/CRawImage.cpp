#include <whycon/common/CRawImage.hpp>

namespace Whycon
{
	CRawImage::CRawImage(size_t wi, size_t he) : width(wi), height(he), size(bpp*width*height), numSaved(0),
												 ownData(true), header(std::vector<unsigned char>(122, 0))
	{
		imgData = (unsigned char*)calloc(size, sizeof(unsigned char));
		/* TODO: Check that this initialisation is ok for Header */
		header = sth;
		header[2] = static_cast<unsigned char>(2, (size + 122) % 256);
		header[3] = static_cast<unsigned char>((size + 122)/256%256);
		header[4] = static_cast<unsigned char>(((size + 122)/256/256)%256);
		header[5] = static_cast<unsigned char>((size + 122)/256/256/256);
		header[10] = 122;
		header[18] = static_cast<unsigned char>(width%256);
		header[19] = static_cast<unsigned char>(width/256);
		header[22] = static_cast<unsigned char>(height%256);
		header[23] = static_cast<unsigned char>(height/256);
		header[34] = static_cast<unsigned char>(size%256);
		header[35] = static_cast<unsigned char>((size/256)%256);
		header[36] = static_cast<unsigned char>(((size/256/256)%256));
		header[37] = static_cast<unsigned char>((size/256/256/256));
	}

	CRawImage::CRawImage(size_t wi, size_t he, unsigned char* datai) : width(wi), height(he), size(bpp*width*height), numSaved(0), ownData(false)
	{
		imgData = datai;
		header = sth;
		header[2] = static_cast<unsigned char>(2, (size + 122) % 256);
		header[3] = static_cast<unsigned char>((size + 122)/256%256);
		header[4] = static_cast<unsigned char>(((size + 122)/256/256)%256);
		header[5] = static_cast<unsigned char>((size + 122)/256/256/256);
		header[10] = 122;
		header[18] = static_cast<unsigned char>(width%256);
		header[19] = static_cast<unsigned char>(width/256);
		header[22] = static_cast<unsigned char>(height%256);
		header[23] = static_cast<unsigned char>(height/256);
		header[34] = static_cast<unsigned char>(size%256);
		header[35] = static_cast<unsigned char>((size/256)%256);
		header[36] = static_cast<unsigned char>(((size/256/256)%256));
		header[37] = static_cast<unsigned char>((size/256/256/256));
	}

	CRawImage::~CRawImage()
	{
		delete imgData;
	}

	int CRawImage::getSaveNumber()
	{
		char name[100];
		FILE* file;
		do
		{
			sprintf(name, "%04i.bmp", numSaved++);
			file = fopen(name, "r");
		} while (file != nullptr);
		return --numSaved;
	}

	void CRawImage::swapRGB()
	{
		for (int j = 0; j < height; j++)
		{
			for (int i = 0; i < width; i++)
			{
				unsigned char a = imgData[(width*j + i)*bpp];
				imgData[(width*j + i)*bpp] = imgData[(width*j + i)*bpp + 2];
				imgData[(width*j + i)*bpp + 2] = a;
			}
		}
	}

	void CRawImage::swap()
	{
		std::vector<unsigned char> newData(size);
		std::list imgDataWrapper(imgData);
		size_t span = width*bpp;
		for (int j = 0; j < height; j++)
		{
		    std::copy(std::begin(imgDataWrapper) + span*(height - 1 - j), std::begin(imgDataWrapper) + span*(height - 1 - j) + span, std::begin(newData) + span*j);

			for (int i = 0; i < width; i++)
			{
				unsigned char a = (newData[(width*j + i)*bpp]);
				newData[(width*j + i)*bpp] = newData[(width*j + i)*bpp + 2];
				newData[(width*j + i)*bpp + 2] = a;
			}
		}
		std::move(newData.begin(), newData.end(), imgData);
	}

	void CRawImage::saveBmp(const char *inName)
	{
		swap();
		std::list imgDataWrapper(imgData);
		std::ofstream os(inName, std::ios::out);
		std::copy(std::begin(header), std::end(header), std::ostream_iterator<long long int>(os));
		std::copy(std::begin(imgDataWrapper), std::end(imgDataWrapper), std::ostream_iterator<long long int>(os));
		swap();
	}

/*	void CRawImage::saveBmp()
	{
		char name[100];
		sprintf(name, "images/%06i.bmp", numSaved++);
		saveBmp(name);
	}*/

/*	bool CRawImage::loadBmp(const char *inName)
	{
		FILE *file = fopen(inName, "rb");
		if (file != NULL)
		{
			if (fread(data, 54, 1, file) != 1) fprintf(stderr, "Warning! Image header could not be read.\n");;
			bpp = 3;
			memcpy(header, data, 54);
			int headerWidth = header[18] + header[19] * 256;
			int headerHeight = header[22] + header[23] * 256;
			if (ownData && (headerWidth != width || headerHeight != height))
			{
				free(data);
				height = headerHeight;
				width = headerWidth;
				size = height * width * bpp;
				data = (unsigned char *) calloc(size, sizeof(unsigned char));
			}
			int offset = header[10] + header[11] * 256;
			if (offset - 54 > 0 && fread(data, offset - 54, 1, file) != 1)
				fprintf(stderr, "Warning! Image header could not be read.\n");;
			if (fread(data, size, 1, file) != 1) fprintf(stderr, "Warning! Image data could not be read.\n");;
			fclose(file);
			swap();
			return true;
		}
		return false;
	}*/

	void CRawImage::plotCenter()
	{
		int centerWidth = 20;
		unsigned char color[] = {255, 0, 0};		// Red
		for (int i = -centerWidth; i < centerWidth; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				imgData[(width * (height / 2 + i) + width / 2 - centerWidth) * bpp + j] = color[j];
				imgData[(width * (height / 2 + i) + width / 2 + centerWidth) * bpp + j] = color[j];
				imgData[(width * (height / 2 - centerWidth) + width / 2 + i) * bpp + j] = color[j];
				imgData[(width * (height / 2 + centerWidth) + width / 2 + i) * bpp + j] = color[j];
			}
		}
	}

	void CRawImage::plotLine(size_t x, size_t y)
	{
		size_t base;
		if (y < 0 || y > height - 1) y = height / 2;
		if (x < 0 || x > width - 1) x = width / 2;
		for (size_t i = 0; i < width; i++)
		{
			if (i == width / 2) i++;
			base = (width * y + i) * bpp;
			imgData[base + 0] = 255;
			imgData[base + 1] = 0;
			imgData[base + 2] = 255;
		}

		for (size_t i = 0; i < height; i++)
		{
			size_t bidx = ((width * i) + x) * 3;
			if (i == height / 2) i++;
			imgData[bidx + 0] = 255;
			imgData[bidx + 1] = 255;
			imgData[bidx + 2] = 0;
		}
	}


/** pocita jas obrazku:
  *  upperHalf == true, pocita se jen z horni poloviny obrazku
  *  upperHalf == false, pocita jen ze spodni poloviny obrazku
  */
	double CRawImage::getOverallBrightness(bool upperHalf)
	{
		size_t step = 5;
		size_t pos, sum;
		int num, satMax, satMin;
		sum = 0;
		num = satMax = satMin = 0;
		size_t limit = 0;
		if (upperHalf) limit = 0;
		else limit = height / 2;
		for (size_t i = limit; i < height / 2 + limit; i += step)
		{
			for (size_t j = 0; j < width; j += step)
			{
				pos = (i * width + j) * bpp;
				if (imgData[pos] >= 250 && imgData[pos + 1] >= 250 && imgData[pos + 2] >= 250) satMax++;
				if (imgData[pos] <= 25 && imgData[pos + 1] <= 25 && imgData[pos + 2] <= 25) satMin++;
				sum += imgData[pos] + imgData[pos + 1] + imgData[pos + 2];
				num++;
			}
		}
		return (sum / num / bpp) + (satMax - satMin) * 100.0 / num;
	}
}
