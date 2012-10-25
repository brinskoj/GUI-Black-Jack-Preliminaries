#pragma once

namespace JohnnyBlackJackPreliminaries {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  labelWelcome;
	protected: 
	private: System::Windows::Forms::Label^  labelDateTime;
	private: System::Windows::Forms::Button^  buttonDateTime;
	private: System::Windows::Forms::Button^  buttonExit;
	private: System::Windows::Forms::Button^  buttonPlayOn;
	private: System::Windows::Forms::Label^  labelInstructions;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->labelWelcome = (gcnew System::Windows::Forms::Label());
			this->labelDateTime = (gcnew System::Windows::Forms::Label());
			this->buttonDateTime = (gcnew System::Windows::Forms::Button());
			this->buttonExit = (gcnew System::Windows::Forms::Button());
			this->buttonPlayOn = (gcnew System::Windows::Forms::Button());
			this->labelInstructions = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// labelWelcome
			// 
			this->labelWelcome->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->labelWelcome->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->labelWelcome->Location = System::Drawing::Point(404, 25);
			this->labelWelcome->Name = L"labelWelcome";
			this->labelWelcome->Size = System::Drawing::Size(483, 165);
			this->labelWelcome->TabIndex = 0;
			this->labelWelcome->Text = L"Welcome Friends and Neighbors to Johnny\'s Black Jack Room";
			this->labelWelcome->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelDateTime
			// 
			this->labelDateTime->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->labelDateTime->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->labelDateTime->Location = System::Drawing::Point(957, 25);
			this->labelDateTime->Name = L"labelDateTime";
			this->labelDateTime->Size = System::Drawing::Size(295, 63);
			this->labelDateTime->TabIndex = 1;
			this->labelDateTime->Text = L"Thursday, January 01, 1970 12:00:00 AM";
			this->labelDateTime->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// buttonDateTime
			// 
			this->buttonDateTime->Location = System::Drawing::Point(1051, 91);
			this->buttonDateTime->Name = L"buttonDateTime";
			this->buttonDateTime->Size = System::Drawing::Size(111, 38);
			this->buttonDateTime->TabIndex = 2;
			this->buttonDateTime->Text = L"Date and Time";
			this->buttonDateTime->UseVisualStyleBackColor = true;
			// 
			// buttonExit
			// 
			this->buttonExit->Location = System::Drawing::Point(1051, 512);
			this->buttonExit->Name = L"buttonExit";
			this->buttonExit->Size = System::Drawing::Size(111, 38);
			this->buttonExit->TabIndex = 3;
			this->buttonExit->Text = L"Exit";
			this->buttonExit->UseVisualStyleBackColor = true;
			// 
			// buttonPlayOn
			// 
			this->buttonPlayOn->Location = System::Drawing::Point(72, 512);
			this->buttonPlayOn->Name = L"buttonPlayOn";
			this->buttonPlayOn->Size = System::Drawing::Size(111, 38);
			this->buttonPlayOn->TabIndex = 4;
			this->buttonPlayOn->Text = L"Play On";
			this->buttonPlayOn->UseVisualStyleBackColor = true;
			// 
			// labelInstructions
			// 
			this->labelInstructions->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->labelInstructions->Location = System::Drawing::Point(310, 204);
			this->labelInstructions->Name = L"labelInstructions";
			this->labelInstructions->Size = System::Drawing::Size(658, 57);
			this->labelInstructions->TabIndex = 5;
			this->labelInstructions->Text = L"Instructions: Click on one card from each column";
			this->labelInstructions->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1264, 562);
			this->Controls->Add(this->labelInstructions);
			this->Controls->Add(this->buttonPlayOn);
			this->Controls->Add(this->buttonExit);
			this->Controls->Add(this->buttonDateTime);
			this->Controls->Add(this->labelDateTime);
			this->Controls->Add(this->labelWelcome);
			this->Name = L"Form1";
			this->Text = L"Johnny\'s Black Jack Preliminaries";
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}

