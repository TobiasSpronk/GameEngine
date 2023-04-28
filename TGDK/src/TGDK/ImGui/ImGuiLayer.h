#pragma once

#include "TGDK/Core/Layer.h"

namespace tgdk {

	class TGDK_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach();
		void OnDetach();
		void OnUpdate();
		void OnEvent(Event& event);
	private:
		float m_Time = 0.0f;
	};

}

