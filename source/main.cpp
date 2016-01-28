#include <iostream>

#include "itkImage.h"
#include "itkImageFileReader.h"
#include "itkImageToVTKImageFilter.h"

#include "vtkImageViewer.h"
#include "vtkRenderWindowInteractor.h"

int main() {
    typedef itk::Image<unsigned short, 3> ImageType;
	typedef itk::ImageFileReader<ImageType> ReaderType;
	typedef itk::ImageToVTKImageFilter<ImageType> FilterType;

	ReaderType::Pointer reader = ReaderType::New();
	FilterType::Pointer connector = FilterType::New();

	reader->SetFileName("testdata/test.dicom");
	connector->SetInput(reader->GetOutput());

	vtkImageViewer *viewer = vtkImageViewer::New();
	vtkRenderWindowInteractor *renderWindowInteractor = vtkRenderWindowInteractor::New();

	viewer->SetupInteractor(renderWindowInteractor);
	viewer->SetInput(connector->GetOutput());
	viewer->Render();
	viewer->SetColorWindow(255);
	viewer->SetColorLevel(128);
	renderWindowInteractor->Start();

    return 0;
}
