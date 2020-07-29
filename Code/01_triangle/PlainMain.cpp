/*
минимальный пример работы с вулканом без лишнего
*/
#define VK_USE_PLATFORM_WIN32_KHR
#define NOMINMAX
#define _USE_MATH_DEFINES // cmath constant
#define _CRT_SECURE_NO_WARNINGS

#include <Windows.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <fstream>
#include <vector>
#include <exception>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vulkan/vulkan.h>
//-----------------------------------------------------------------------------
#pragma comment(lib, "3rdparty.lib")
#pragma comment(lib, "Framework.lib")
#pragma comment(lib, "vulkan-1.lib")

// Set to "true" to enable Vulkan's validation layers (see vulkandebug.cpp for details)
#define ENABLE_VALIDATION false
// Set to "true" to use staging buffers for uploading vertex and index data to device local memory
// See "prepareVertices" for details on what's staging and on why to use it
#define USE_STAGING true

void VulkanExampleBase(bool enableValidation) // конструктор
{

}

void VulkanExample() // конструктор
{
	VulkanExampleBase(ENABLE_VALIDATION);


}




//-----------------------------------------------------------------------------
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return (DefWindowProc(hWnd, uMsg, wParam, lParam));
}
int WINAPI wWinMain(
	[[maybe_unused]] _In_ HINSTANCE hInstance,
	[[maybe_unused]] _In_opt_ HINSTANCE hPrevInstance,
	[[maybe_unused]] _In_ LPWSTR lpCmdLine,
	[[maybe_unused]] _In_ int nCmdShow)
{
	VulkanExample();


	return 0;
}