#include "imageLoader.h"

ImageLoader::ImageLoader()
{
    m_isLoading = false;
}

void ImageLoader::load(string path)
{
    m_path = path;
    m_isLoading = true;
    startThread();
}

void ImageLoader::threadedFunction()
{
    ofLoadImage(m_image, m_path);
    m_isLoaded = true;
}

