#pragma once

#include "BasePanel.h"

class ToolPanel : public BasePanel
{
public:
	bool isMaximizedPressed = false;

	void OnRender(float windowSizeX, float windowSizeY) override;
};

