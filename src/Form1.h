#pragma once
#include <string>
#include "Resultado.h"
#include "pch.h"
#include <tuple>
#include <fstream>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <math.h>
#include <stdio.h>
namespace CppCLRWinFormsProject {
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace std;
    using namespace System::Reflection;
    using namespace System::IO;
    /// <summary>
    /// Summary for Form1
    /// </summary>
    public ref class Form1 : public System::Windows::Forms::Form
    {
        //VARIABLES
        //float Etmedio, Irr, Espacio,Pt;//DECLARACION DE VARIABLES TOMADASPOR EL PROGRAMA
        float Etmedio, Pt, HSP, Espacio;
        float Vnom, Ctmax, Cnombat, Daut = 4, Pdmax = 0.7; //VARIABLES PARACALCULOS
        float E1, E2, E3, E4, E5, E6, E7, E8, E9, E10, E11, E12;
        float G1, G2, G3, G4, G5, G6, G7, G8, G9, G10, G11, G12;
        float autonum, Etotal, por;
        float Vinmax, Iinmax;//datos para el regulador
        float Pinv;//datos del inversor
        float auxnum;
        int comp, Nps, Npp, Npt, Epanel;
        bool tipo=true;
        //BANCO DE DATOS
        float  Pm = 450, Im = 10.7, Vm = 42.06, Isc = 11.36, Voc = 50.43, prpan=170 , npanel = 0.9, kt = 0.7, areapanel=2.20; //TSM450W Beyond Sun
        float  ninv = 0.95;
        //DECLARACIÓN DE ETIQUETAS
        private: System::Windows::Forms::Label^ label1;
        private: System::Windows::Forms::Label^ label5;
        private: System::Windows::Forms::Label^ lbl_potinv;
        private: System::Windows::Forms::Label^ lbl_invd;
        private: System::Windows::Forms::Label^ lbl_inv;
        private: System::Windows::Forms::Label^ lbl_batd;
        private: System::Windows::Forms::Label^ lbl_Nps;
        private: System::Windows::Forms::Label^ lbl_bat;
        private: System::Windows::Forms::Label^ label12;
        private: System::Windows::Forms::Label^ lbl_pand;
        private: System::Windows::Forms::Label^ lbl_pan;
        private: System::Windows::Forms::Label^ lbl_Vmaxreg;
        private: System::Windows::Forms::Label^ lbl_regd;
        private: System::Windows::Forms::Label^ lbl_reg;
        private: System::Windows::Forms::Label^ label21;
        private: System::Windows::Forms::Label^ label22;
        private: System::Windows::Forms::Label^ label23;
        private: System::Windows::Forms::Label^ label24;
        private: System::Windows::Forms::Label^ label25;
        private: System::Windows::Forms::Label^ label26;
        private: System::Windows::Forms::Label^ label27;
        private: System::Windows::Forms::Label^ label28;
        private: System::Windows::Forms::Label^ label29;
        private: System::Windows::Forms::Label^ label30;
        private: System::Windows::Forms::Label^ label31;
        private: System::Windows::Forms::Label^ label32;
        private: System::Windows::Forms::Label^ label39;
        private: System::Windows::Forms::Label^ label40;
        private: System::Windows::Forms::Label^ label41;
        private: System::Windows::Forms::Label^ label44;
        private: System::Windows::Forms::Label^ label45;
        private: System::Windows::Forms::Label^ label46;
        private: System::Windows::Forms::Label^ label47;
        private: System::Windows::Forms::Label^ label48;
        private: System::Windows::Forms::Label^ label49;
        private: System::Windows::Forms::Label^ label50;
        private: System::Windows::Forms::Label^ label51;
        private: System::Windows::Forms::Label^ lbl_Npp;
        private: System::Windows::Forms::Label^ lbl_Vnom;
        private: System::Windows::Forms::Label^ lbl_cap;
        private: System::Windows::Forms::Label^ lbl_Npt;
        private: System::Windows::Forms::Label^ lbl_Imaxreg;
        private: System::Windows::Forms::Label^ label6;
        private: System::Windows::Forms::Label^ lbl_tipo;
        private: System::Windows::Forms::Label^ lbl_ucap;
        private: System::Windows::Forms::Label^ lbl_uvnom;
        private: System::Windows::Forms::Label^ lbl_uvmax;
        private: System::Windows::Forms::Label^ lbl_uimax;
        private: System::Windows::Forms::Label^ lbl_upnom;
        private: System::Windows::Forms::Label^ label2;
        private: System::Windows::Forms::Label^ label4;
        private: System::Windows::Forms::TextBox^ tb_E10;
        private: System::Windows::Forms::TextBox^ tb_E9;
        private: System::Windows::Forms::TextBox^ tb_E8;
        private: System::Windows::Forms::TextBox^ tb_E7;
        private: System::Windows::Forms::TextBox^ tb_E6;
        private: System::Windows::Forms::TextBox^ tb_E5;
        private: System::Windows::Forms::TextBox^ tb_E4;
        private: System::Windows::Forms::TextBox^ tb_E3;
        private: System::Windows::Forms::TextBox^ tb_E2;
        private: System::Windows::Forms::TextBox^ tb_E11;
        private: System::Windows::Forms::TextBox^ tb_E12;
        private: System::Windows::Forms::TextBox^ tb_long;
        private: System::Windows::Forms::TextBox^ tb_inclinacion;
        private: System::Windows::Forms::TextBox^ tb_azimut;
        private: System::Windows::Forms::TextBox^ tb_Imp;
        private: System::Windows::Forms::TextBox^ tb_Pmp;
        private: System::Windows::Forms::TextBox^ tb_Vmp;
        private: System::Windows::Forms::TextBox^ tb_Voc;
        private: System::Windows::Forms::TextBox^ tb_Isc;
        private: System::Windows::Forms::TextBox^ tb_precio;
        private: System::Windows::Forms::TextBox^ tb_potencia;
        private: System::Windows::Forms::TextBox^ tb_E1;
        private: System::Windows::Forms::TextBox^ tb_lat;
        private: System::Windows::Forms::Panel^ panel1;
        private: System::Windows::Forms::Panel^ panel3;
        private: System::Windows::Forms::Button^ button2;
        private: System::Windows::Forms::Button^ button3;
        private: System::Windows::Forms::Label^ label7;
        private: System::Windows::Forms::Label^ label8;
        private: System::Windows::Forms::TextBox^ tb_area;
        private: System::Windows::Forms::Button^ button4;
        private: System::Windows::Forms::Label^ label10;
        private: System::Windows::Forms::RichTextBox^ rtb_1;
        private: System::Windows::Forms::RichTextBox^ rtb_15;
        private: System::Windows::Forms::RichTextBox^ rtb_8;
        private: System::Windows::Forms::RichTextBox^ rtb_9;
        private: System::Windows::Forms::RichTextBox^ rtb_16;
        private: System::Windows::Forms::RichTextBox^ rtb_2;
        private: System::Windows::Forms::RichTextBox^ rtb_10;
        private: System::Windows::Forms::RichTextBox^ rtb_17;
        private: System::Windows::Forms::RichTextBox^ rtb_3;
        private: System::Windows::Forms::RichTextBox^ rtb_11;
        private: System::Windows::Forms::RichTextBox^ rtb_18;
        private: System::Windows::Forms::RichTextBox^ rtb_5;
        private: System::Windows::Forms::RichTextBox^ rtb_12;
        private: System::Windows::Forms::RichTextBox^ rtb_19;
        private: System::Windows::Forms::RichTextBox^ rtb_4;
        private: System::Windows::Forms::RichTextBox^ rtb_13;
        private: System::Windows::Forms::RichTextBox^ rtb_20;
        private: System::Windows::Forms::RichTextBox^ rtb_6;
        private: System::Windows::Forms::RichTextBox^ rtb_14;
        private: System::Windows::Forms::RichTextBox^ rtb_21;
        private: System::Windows::Forms::RichTextBox^ rtb_7;
        private: System::Windows::Forms::Label^ lbl_esp;
        private: System::Windows::Forms::Label^ label3;
        private: System::Windows::Forms::Label^ label11;
        private: System::Windows::Forms::Button^ button1;
        public:
            Form1(void)
            {
                InitializeComponent();
                //
                //TODO: Add the constructor code here
                //
            }
        protected: /// <summary>
        /// Clean up any resources being used.
        /// </summary>
            ~Form1()
            {
                if (components)
                {
                    delete components;
                }
            }
        protected: private: /// <summary>
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
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->tb_E1 = (gcnew System::Windows::Forms::TextBox());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->tb_lat = (gcnew System::Windows::Forms::TextBox());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->label5 = (gcnew System::Windows::Forms::Label());
            this->tb_potencia = (gcnew System::Windows::Forms::TextBox());
            this->lbl_potinv = (gcnew System::Windows::Forms::Label());
            this->lbl_invd = (gcnew System::Windows::Forms::Label());
            this->lbl_inv = (gcnew System::Windows::Forms::Label());
            this->lbl_batd = (gcnew System::Windows::Forms::Label());
            this->lbl_Nps = (gcnew System::Windows::Forms::Label());
            this->lbl_bat = (gcnew System::Windows::Forms::Label());
            this->label12 = (gcnew System::Windows::Forms::Label());
            this->lbl_pand = (gcnew System::Windows::Forms::Label());
            this->lbl_pan = (gcnew System::Windows::Forms::Label());
            this->lbl_Vmaxreg = (gcnew System::Windows::Forms::Label());
            this->lbl_regd = (gcnew System::Windows::Forms::Label());
            this->lbl_reg = (gcnew System::Windows::Forms::Label());
            this->label21 = (gcnew System::Windows::Forms::Label());
            this->label22 = (gcnew System::Windows::Forms::Label());
            this->label23 = (gcnew System::Windows::Forms::Label());
            this->label24 = (gcnew System::Windows::Forms::Label());
            this->label25 = (gcnew System::Windows::Forms::Label());
            this->label26 = (gcnew System::Windows::Forms::Label());
            this->label27 = (gcnew System::Windows::Forms::Label());
            this->label28 = (gcnew System::Windows::Forms::Label());
            this->label29 = (gcnew System::Windows::Forms::Label());
            this->label30 = (gcnew System::Windows::Forms::Label());
            this->label31 = (gcnew System::Windows::Forms::Label());
            this->label32 = (gcnew System::Windows::Forms::Label());
            this->tb_E10 = (gcnew System::Windows::Forms::TextBox());
            this->tb_E9 = (gcnew System::Windows::Forms::TextBox());
            this->tb_E8 = (gcnew System::Windows::Forms::TextBox());
            this->tb_E7 = (gcnew System::Windows::Forms::TextBox());
            this->tb_E6 = (gcnew System::Windows::Forms::TextBox());
            this->tb_E5 = (gcnew System::Windows::Forms::TextBox());
            this->tb_E4 = (gcnew System::Windows::Forms::TextBox());
            this->tb_E3 = (gcnew System::Windows::Forms::TextBox());
            this->tb_E2 = (gcnew System::Windows::Forms::TextBox());
            this->tb_E11 = (gcnew System::Windows::Forms::TextBox());
            this->tb_E12 = (gcnew System::Windows::Forms::TextBox());
            this->tb_long = (gcnew System::Windows::Forms::TextBox());
            this->tb_inclinacion = (gcnew System::Windows::Forms::TextBox());
            this->tb_azimut = (gcnew System::Windows::Forms::TextBox());
            this->label39 = (gcnew System::Windows::Forms::Label());
            this->label40 = (gcnew System::Windows::Forms::Label());
            this->label41 = (gcnew System::Windows::Forms::Label());
            this->label44 = (gcnew System::Windows::Forms::Label());
            this->label45 = (gcnew System::Windows::Forms::Label());
            this->tb_Imp = (gcnew System::Windows::Forms::TextBox());
            this->tb_Pmp = (gcnew System::Windows::Forms::TextBox());
            this->label46 = (gcnew System::Windows::Forms::Label());
            this->label47 = (gcnew System::Windows::Forms::Label());
            this->label48 = (gcnew System::Windows::Forms::Label());
            this->tb_Vmp = (gcnew System::Windows::Forms::TextBox());
            this->tb_Voc = (gcnew System::Windows::Forms::TextBox());
            this->tb_Isc = (gcnew System::Windows::Forms::TextBox());
            this->label49 = (gcnew System::Windows::Forms::Label());
            this->label50 = (gcnew System::Windows::Forms::Label());
            this->label51 = (gcnew System::Windows::Forms::Label());
            this->tb_precio = (gcnew System::Windows::Forms::TextBox());
            this->lbl_Npp = (gcnew System::Windows::Forms::Label());
            this->lbl_Vnom = (gcnew System::Windows::Forms::Label());
            this->lbl_cap = (gcnew System::Windows::Forms::Label());
            this->lbl_Npt = (gcnew System::Windows::Forms::Label());
            this->panel1 = (gcnew System::Windows::Forms::Panel());
            this->panel3 = (gcnew System::Windows::Forms::Panel());
            this->button4 = (gcnew System::Windows::Forms::Button());
            this->button2 = (gcnew System::Windows::Forms::Button());
            this->lbl_Imaxreg = (gcnew System::Windows::Forms::Label());
            this->button3 = (gcnew System::Windows::Forms::Button());
            this->label6 = (gcnew System::Windows::Forms::Label());
            this->lbl_tipo = (gcnew System::Windows::Forms::Label());
            this->lbl_ucap = (gcnew System::Windows::Forms::Label());
            this->lbl_uvnom = (gcnew System::Windows::Forms::Label());
            this->lbl_uvmax = (gcnew System::Windows::Forms::Label());
            this->lbl_uimax = (gcnew System::Windows::Forms::Label());
            this->lbl_upnom = (gcnew System::Windows::Forms::Label());
            this->label7 = (gcnew System::Windows::Forms::Label());
            this->label8 = (gcnew System::Windows::Forms::Label());
            this->tb_area = (gcnew System::Windows::Forms::TextBox());
            this->label10 = (gcnew System::Windows::Forms::Label());
            this->rtb_1 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_15 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_8 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_9 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_16 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_2 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_10 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_17 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_3 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_11 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_18 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_5 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_12 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_19 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_4 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_13 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_20 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_6 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_14 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_21 = (gcnew System::Windows::Forms::RichTextBox());
            this->rtb_7 = (gcnew System::Windows::Forms::RichTextBox());
            this->lbl_esp = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->label11 = (gcnew System::Windows::Forms::Label());
            this->panel1->SuspendLayout();
            this->panel3->SuspendLayout();
            this->SuspendLayout();
            //
            // label1
            //
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label1->Location = System::Drawing::Point(350, 89);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(200, 31);
            this->label1->TabIndex = 0;
            this->label1->Text = L"2. Consumo[kWh]";
            //
            // tb_E1
            //
            this->tb_E1->Location = System::Drawing::Point(470, 151);
            this->tb_E1->Name = L"tb_E1";
            this->tb_E1->Size = System::Drawing::Size(174, 22);
            this->tb_E1->TabIndex = 1;
            //
            // label2
            //
            this->label2->AutoSize = true;
            this->label2->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label2->Location = System::Drawing::Point(708, 89);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(315, 31);
            this->label2->TabIndex = 50;
            this->label2->Text = L"3. Ubicación de la instalación";
            //
            // tb_lat
            //
            this->tb_lat->Location = System::Drawing::Point(828, 151);
            this->tb_lat->Name = L"tb_lat";
            this->tb_lat->Size = System::Drawing::Size(174, 22);
            this->tb_lat->TabIndex = 48;
            //
            // button1
            //
            this->button1->BackColor = System::Drawing::Color::Gray;
            this->button1->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->button1->Location = System::Drawing::Point(814, 449);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(96, 41);
            this->button1->TabIndex = 76;
            this->button1->Text = L"Calcula";
            this->button1->UseVisualStyleBackColor = false;
            this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
            //
            // label4
            //
            this->label4->AutoSize = true;
            this->label4->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label4->ForeColor = System::Drawing::SystemColors::ControlLightLight;
            this->label4->Location = System::Drawing::Point(35, 27);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(279, 31);
            this->label4->TabIndex = 7;
            this->label4->Text = L"DIMENSIONADO BÁSICO";
            //
            // label5
            //
            this->label5->AutoSize = true;
            this->label5->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label5->Location = System::Drawing::Point(354, 658);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(107, 23);
            this->label5->TabIndex = 8;
            this->label5->Text = L"Potencia [W]";
            //
            // tb_potencia
            //
            this->tb_potencia->Location = System::Drawing::Point(470, 660);
            this->tb_potencia->Name = L"tb_potencia";
            this->tb_potencia->Size = System::Drawing::Size(174, 22);
            this->tb_potencia->TabIndex = 75;
            //
            // lbl_potinv
            //
            this->lbl_potinv->AutoSize = true;
            this->lbl_potinv->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->lbl_potinv->Location = System::Drawing::Point(1646, 408);
            this->lbl_potinv->Name = L"lbl_potinv";
            this->lbl_potinv->Size = System::Drawing::Size(104, 23);
            this->lbl_potinv->TabIndex = 25;
            this->lbl_potinv->Text = L"3157.894775";
            this->lbl_potinv->Visible = false;
            //
            // lbl_invd
            //
            this->lbl_invd->AutoSize = true;
            this->lbl_invd->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->lbl_invd->Location = System::Drawing::Point(1487, 410);
            this->lbl_invd->Name = L"lbl_invd";
            this->lbl_invd->Size = System::Drawing::Size(147, 23);
            this->lbl_invd->TabIndex = 24;
            this->lbl_invd->Text = L"Potencia nominal:";
            this->lbl_invd->Visible = false;
            //
            // lbl_inv
            //
            this->lbl_inv->AutoSize = true;
            this->lbl_inv->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->lbl_inv->Location = System::Drawing::Point(1487, 378);
            this->lbl_inv->Name = L"lbl_inv";
            this->lbl_inv->Size = System::Drawing::Size(76, 23);
            this->lbl_inv->TabIndex = 23;
            this->lbl_inv->Text = L"Inversor:";
            this->lbl_inv->Visible = false;
            //
            // lbl_batd
            //
            this->lbl_batd->AutoSize = true;
            this->lbl_batd->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->lbl_batd->Location = System::Drawing::Point(1487, 308);
            this->lbl_batd->Name = L"lbl_batd";
            this->lbl_batd->Size = System::Drawing::Size(138, 46);
            this->lbl_batd->TabIndex = 22;
            this->lbl_batd->Text = L"Capacidad:\nTensión nominal:";
            this->lbl_batd->Visible = false;
            //
            // lbl_Nps
            //
            this->lbl_Nps->AutoSize = true;
            this->lbl_Nps->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->lbl_Nps->Location = System::Drawing::Point(1646, 176);
            this->lbl_Nps->Name = L"lbl_Nps";
            this->lbl_Nps->Size = System::Drawing::Size(22, 23);
            this->lbl_Nps->TabIndex = 21;
            this->lbl_Nps->Text = L"...";
            this->lbl_Nps->Visible = false;
            //
            // lbl_bat
            //
            this->lbl_bat->AutoSize = true;
            this->lbl_bat->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->lbl_bat->Location = System::Drawing::Point(1487, 273);
            this->lbl_bat->Name = L"lbl_bat";
            this->lbl_bat->Size = System::Drawing::Size(67, 23);
            this->lbl_bat->TabIndex = 20;
            this->lbl_bat->Text = L"Batería:";
            this->lbl_bat->Visible = false;
            //
            // label12
            //
            this->label12->AutoSize = true;
            this->label12->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label12->Location = System::Drawing::Point(1485, 89);
            this->label12->Name = L"label12";
            this->label12->Size = System::Drawing::Size(199, 31);
            this->label12->TabIndex = 19;
            this->label12->Text = L"DIMENSIONADO ";
            this->label12->Visible = false;
            //
            // lbl_pand
            //
            this->lbl_pand->AutoSize = true;
            this->lbl_pand->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->lbl_pand->Location = System::Drawing::Point(1487, 176);
            this->lbl_pand->Name = L"lbl_pand";
            this->lbl_pand->Size = System::Drawing::Size(120, 92);
            this->lbl_pand->TabIndex = 18;
            this->lbl_pand->Text = L"Serie:\nParalelo:\nTotal:\nArea ocupada:";
            this->lbl_pand->Visible = false;
            //
            // lbl_pan
            //
            this->lbl_pan->AutoSize = true;
            this->lbl_pan->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->lbl_pan->Location = System::Drawing::Point(1487, 144);
            this->lbl_pan->Name = L"lbl_pan";
            this->lbl_pan->Size = System::Drawing::Size(72, 23);
            this->lbl_pan->TabIndex = 15;
            this->lbl_pan->Text = L"Paneles:";
            this->lbl_pan->Visible = false;
            //
            // lbl_Vmaxreg
            //
            this->lbl_Vmaxreg->AutoSize = true;
            this->lbl_Vmaxreg->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->lbl_Vmaxreg->Location = System::Drawing::Point(1646, 483);
            this->lbl_Vmaxreg->Name = L"lbl_Vmaxreg";
            this->lbl_Vmaxreg->Size = System::Drawing::Size(86, 23);
            this->lbl_Vmaxreg->TabIndex = 29;
            this->lbl_Vmaxreg->Text = L"55.473000";
            this->lbl_Vmaxreg->Visible = false;
            //
            // lbl_regd
            //
            this->lbl_regd->AutoSize = true;
            this->lbl_regd->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->lbl_regd->Location = System::Drawing::Point(1487, 483);
            this->lbl_regd->Name = L"lbl_regd";
            this->lbl_regd->Size = System::Drawing::Size(150, 46);
            this->lbl_regd->TabIndex = 27;
            this->lbl_regd->Text = L"Tensión máxima: \nCorriente maxima:";
            this->lbl_regd->Visible = false;
            //
            // lbl_reg
            //
            this->lbl_reg->AutoSize = true;
            this->lbl_reg->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->lbl_reg->Location = System::Drawing::Point(1487, 453);
            this->lbl_reg->Name = L"lbl_reg";
            this->lbl_reg->Size = System::Drawing::Size(93, 23);
            this->lbl_reg->TabIndex = 26;
            this->lbl_reg->Text = L"Regulador:";
            this->lbl_reg->Visible = false;
            //
            // label21
            //
            this->label21->AutoSize = true;
            this->label21->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label21->Location = System::Drawing::Point(354, 149);
            this->label21->Name = L"label21";
            this->label21->Size = System::Drawing::Size(54, 23);
            this->label21->TabIndex = 30;
            this->label21->Text = L"Enero";
            //
            // label22
            //
            this->label22->AutoSize = true;
            this->label22->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label22->Location = System::Drawing::Point(352, 359);
            this->label22->Name = L"label22";
            this->label22->Size = System::Drawing::Size(50, 23);
            this->label22->TabIndex = 31;
            this->label22->Text = L"Junio";
            //
            // label23
            //
            this->label23->AutoSize = true;
            this->label23->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label23->Location = System::Drawing::Point(352, 315);
            this->label23->Name = L"label23";
            this->label23->Size = System::Drawing::Size(52, 23);
            this->label23->TabIndex = 32;
            this->label23->Text = L"Mayo";
            //
            // label24
            //
            this->label24->AutoSize = true;
            this->label24->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label24->Location = System::Drawing::Point(354, 271);
            this->label24->Name = L"label24";
            this->label24->Size = System::Drawing::Size(45, 23);
            this->label24->TabIndex = 33;
            this->label24->Text = L"Abril";
            //
            // label25
            //
            this->label25->AutoSize = true;
            this->label25->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label25->Location = System::Drawing::Point(352, 231);
            this->label25->Name = L"label25";
            this->label25->Size = System::Drawing::Size(58, 23);
            this->label25->TabIndex = 34;
            this->label25->Text = L"Marzo";
            //
            // label26
            //
            this->label26->AutoSize = true;
            this->label26->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label26->Location = System::Drawing::Point(352, 192);
            this->label26->Name = L"label26";
            this->label26->Size = System::Drawing::Size(67, 23);
            this->label26->TabIndex = 35;
            this->label26->Text = L"Febrero";
            //
            // label27
            //
            this->label27->AutoSize = true;
            this->label27->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label27->Location = System::Drawing::Point(352, 574);
            this->label27->Name = L"label27";
            this->label27->Size = System::Drawing::Size(94, 23);
            this->label27->TabIndex = 36;
            this->label27->Text = L"Noviembre";
            //
            // label28
            //
            this->label28->AutoSize = true;
            this->label28->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label28->Location = System::Drawing::Point(354, 532);
            this->label28->Name = L"label28";
            this->label28->Size = System::Drawing::Size(72, 23);
            this->label28->TabIndex = 37;
            this->label28->Text = L"Octubre";
            //
            // label29
            //
            this->label29->AutoSize = true;
            this->label29->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label29->Location = System::Drawing::Point(352, 404);
            this->label29->Name = L"label29";
            this->label29->Size = System::Drawing::Size(44, 23);
            this->label29->TabIndex = 38;
            this->label29->Text = L"Julio";
            //
            // label30
            //
            this->label30->AutoSize = true;
            this->label30->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label30->Location = System::Drawing::Point(352, 449);
            this->label30->Name = L"label30";
            this->label30->Size = System::Drawing::Size(64, 23);
            this->label30->TabIndex = 39;
            this->label30->Text = L"Agosto";
            //
            // label31
            //
            this->label31->AutoSize = true;
            this->label31->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label31->Location = System::Drawing::Point(352, 490);
            this->label31->Name = L"label31";
            this->label31->Size = System::Drawing::Size(97, 23);
            this->label31->TabIndex = 40;
            this->label31->Text = L"Septiembre";
            //
            // label32
            //
            this->label32->AutoSize = true;
            this->label32->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label32->Location = System::Drawing::Point(354, 618);
            this->label32->Name = L"label32";
            this->label32->Size = System::Drawing::Size(87, 23);
            this->label32->TabIndex = 41;
            this->label32->Text = L"Diciembre";
            //
            // tb_E10
            //
            this->tb_E10->Location = System::Drawing::Point(470, 534);
            this->tb_E10->Name = L"tb_E10";
            this->tb_E10->Size = System::Drawing::Size(174, 22);
            this->tb_E10->TabIndex = 45;
            //
            // tb_E9
            //
            this->tb_E9->Location = System::Drawing::Point(470, 492);
            this->tb_E9->Name = L"tb_E9";
            this->tb_E9->Size = System::Drawing::Size(174, 22);
            this->tb_E9->TabIndex = 44;
            //
            // tb_E8
            //
            this->tb_E8->Location = System::Drawing::Point(470, 451);
            this->tb_E8->Name = L"tb_E8";
            this->tb_E8->Size = System::Drawing::Size(174, 22);
            this->tb_E8->TabIndex = 43;
            //
            // tb_E7
            //
            this->tb_E7->Location = System::Drawing::Point(470, 406);
            this->tb_E7->Name = L"tb_E7";
            this->tb_E7->Size = System::Drawing::Size(174, 22);
            this->tb_E7->TabIndex = 42;
            //
            // tb_E6
            //
            this->tb_E6->Location = System::Drawing::Point(470, 361);
            this->tb_E6->Name = L"tb_E6";
            this->tb_E6->Size = System::Drawing::Size(174, 22);
            this->tb_E6->TabIndex = 9;
            //
            // tb_E5
            //
            this->tb_E5->Location = System::Drawing::Point(470, 317);
            this->tb_E5->Name = L"tb_E5";
            this->tb_E5->Size = System::Drawing::Size(174, 22);
            this->tb_E5->TabIndex = 6;
            //
            // tb_E4
            //
            this->tb_E4->Location = System::Drawing::Point(470, 273);
            this->tb_E4->Name = L"tb_E4";
            this->tb_E4->Size = System::Drawing::Size(174, 22);
            this->tb_E4->TabIndex = 5;
            //
            // tb_E3
            //
            this->tb_E3->Location = System::Drawing::Point(470, 232);
            this->tb_E3->Name = L"tb_E3";
            this->tb_E3->Size = System::Drawing::Size(174, 22);
            this->tb_E3->TabIndex = 4;
            //
            // tb_E2
            //
            this->tb_E2->Location = System::Drawing::Point(470, 194);
            this->tb_E2->Name = L"tb_E2";
            this->tb_E2->Size = System::Drawing::Size(174, 22);
            this->tb_E2->TabIndex = 2;
            //
            // tb_E11
            //
            this->tb_E11->Location = System::Drawing::Point(470, 576);
            this->tb_E11->Name = L"tb_E11";
            this->tb_E11->Size = System::Drawing::Size(174, 22);
            this->tb_E11->TabIndex = 46;
            //
            // tb_E12
            //
            this->tb_E12->Location = System::Drawing::Point(470, 620);
            this->tb_E12->Name = L"tb_E12";
            this->tb_E12->Size = System::Drawing::Size(174, 22);
            this->tb_E12->TabIndex = 47;
            //
            // tb_long
            //
            this->tb_long->Location = System::Drawing::Point(828, 194);
            this->tb_long->Name = L"tb_long";
            this->tb_long->Size = System::Drawing::Size(174, 22);
            this->tb_long->TabIndex = 49;
            //
            // tb_inclinacion
            //
            this->tb_inclinacion->Location = System::Drawing::Point(828, 232);
            this->tb_inclinacion->Name = L"tb_inclinacion";
            this->tb_inclinacion->Size = System::Drawing::Size(174, 22);
            this->tb_inclinacion->TabIndex = 51;
            //
            // tb_azimut
            //
            this->tb_azimut->Location = System::Drawing::Point(828, 273);
            this->tb_azimut->Name = L"tb_azimut";
            this->tb_azimut->Size = System::Drawing::Size(174, 22);
            this->tb_azimut->TabIndex = 52;
            //
            // label39
            //
            this->label39->AutoSize = true;
            this->label39->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label39->Location = System::Drawing::Point(710, 193);
            this->label39->Name = L"label39";
            this->label39->Size = System::Drawing::Size(100, 23);
            this->label39->TabIndex = 59;
            this->label39->Text = L"Longitud [º]";
            //
            // label40
            //
            this->label40->AutoSize = true;
            this->label40->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label40->Location = System::Drawing::Point(710, 231);
            this->label40->Name = L"label40";
            this->label40->Size = System::Drawing::Size(114, 23);
            this->label40->TabIndex = 58;
            this->label40->Text = L"Inclinación [º]";
            //
            // label41
            //
            this->label41->AutoSize = true;
            this->label41->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label41->Location = System::Drawing::Point(712, 271);
            this->label41->Name = L"label41";
            this->label41->Size = System::Drawing::Size(86, 23);
            this->label41->TabIndex = 57;
            this->label41->Text = L"Azimut [º]";
            //
            // label44
            //
            this->label44->AutoSize = true;
            this->label44->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label44->Location = System::Drawing::Point(712, 149);
            this->label44->Name = L"label44";
            this->label44->Size = System::Drawing::Size(85, 23);
            this->label44->TabIndex = 54;
            this->label44->Text = L"Latitud [º]";
            //
            // label45
            //
            this->label45->AutoSize = true;
            this->label45->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label45->Location = System::Drawing::Point(1079, 89);
            this->label45->Name = L"label45";
            this->label45->Size = System::Drawing::Size(238, 31);
            this->label45->TabIndex = 78;
            this->label45->Text = L"4. Selección del panel";
            //
            // tb_Imp
            //
            this->tb_Imp->Location = System::Drawing::Point(1264, 194);
            this->tb_Imp->Name = L"tb_Imp";
            this->tb_Imp->Size = System::Drawing::Size(174, 22);
            this->tb_Imp->TabIndex = 84;
            this->tb_Imp->Text = L"10.7";
            //
            // tb_Pmp
            //
            this->tb_Pmp->Location = System::Drawing::Point(1264, 232);
            this->tb_Pmp->Name = L"tb_Pmp";
            this->tb_Pmp->Size = System::Drawing::Size(174, 22);
            this->tb_Pmp->TabIndex = 83;
            this->tb_Pmp->Text = L"450";
            //
            // label46
            //
            this->label46->AutoSize = true;
            this->label46->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label46->Location = System::Drawing::Point(1085, 193);
            this->label46->Name = L"label46";
            this->label46->Size = System::Drawing::Size(66, 23);
            this->label46->TabIndex = 82;
            this->label46->Text = L"Imp [A]";
            //
            // label47
            //
            this->label47->AutoSize = true;
            this->label47->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label47->Location = System::Drawing::Point(1083, 231);
            this->label47->Name = L"label47";
            this->label47->Size = System::Drawing::Size(85, 23);
            this->label47->TabIndex = 81;
            this->label47->Text = L"Pmp [Wp]";
            //
            // label48
            //
            this->label48->AutoSize = true;
            this->label48->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label48->Location = System::Drawing::Point(1085, 149);
            this->label48->Name = L"label48";
            this->label48->Size = System::Drawing::Size(71, 23);
            this->label48->TabIndex = 80;
            this->label48->Text = L"Vmp [V]";
            //
            // tb_Vmp
            //
            this->tb_Vmp->Location = System::Drawing::Point(1264, 151);
            this->tb_Vmp->Name = L"tb_Vmp";
            this->tb_Vmp->Size = System::Drawing::Size(174, 22);
            this->tb_Vmp->TabIndex = 79;
            this->tb_Vmp->Text = L"42.06";
            //
            // tb_Voc
            //
            this->tb_Voc->Location = System::Drawing::Point(1266, 272);
            this->tb_Voc->Name = L"tb_Voc";
            this->tb_Voc->Size = System::Drawing::Size(174, 22);
            this->tb_Voc->TabIndex = 88;
            this->tb_Voc->Text = L"50.43";
            //
            // tb_Isc
            //
            this->tb_Isc->Location = System::Drawing::Point(1266, 310);
            this->tb_Isc->Name = L"tb_Isc";
            this->tb_Isc->Size = System::Drawing::Size(174, 22);
            this->tb_Isc->TabIndex = 87;
            this->tb_Isc->Text = L"11.36";
            //
            // label49
            //
            this->label49->AutoSize = true;
            this->label49->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label49->Location = System::Drawing::Point(1085, 271);
            this->label49->Name = L"label49";
            this->label49->Size = System::Drawing::Size(64, 23);
            this->label49->TabIndex = 86;
            this->label49->Text = L"Voc [V]";
            //
            // label50
            //
            this->label50->AutoSize = true;
            this->label50->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label50->Location = System::Drawing::Point(1085, 309);
            this->label50->Name = L"label50";
            this->label50->Size = System::Drawing::Size(56, 23);
            this->label50->TabIndex = 85;
            this->label50->Text = L"Isc [A]";
            //
            // label51
            //
            this->label51->AutoSize = true;
            this->label51->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label51->Location = System::Drawing::Point(1085, 350);
            this->label51->Name = L"label51";
            this->label51->Size = System::Drawing::Size(81, 23);
            this->label51->TabIndex = 89;
            this->label51->Text = L"Precio [€]";
            //
            // tb_precio
            //
            this->tb_precio->Location = System::Drawing::Point(1266, 352);
            this->tb_precio->Name = L"tb_precio";
            this->tb_precio->Size = System::Drawing::Size(174, 22);
            this->tb_precio->TabIndex = 90;
            this->tb_precio->Text = L"170";
            //
            // lbl_Npp
            //
            this->lbl_Npp->AutoSize = true;
            this->lbl_Npp->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->lbl_Npp->Location = System::Drawing::Point(1646, 199);
            this->lbl_Npp->Name = L"lbl_Npp";
            this->lbl_Npp->Size = System::Drawing::Size(22, 23);
            this->lbl_Npp->TabIndex = 91;
            this->lbl_Npp->Text = L"...";
            this->lbl_Npp->Visible = false;
            //
            // lbl_Vnom
            //
            this->lbl_Vnom->AutoSize = true;
            this->lbl_Vnom->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->lbl_Vnom->Location = System::Drawing::Point(1646, 332);
            this->lbl_Vnom->Name = L"lbl_Vnom";
            this->lbl_Vnom->Size = System::Drawing::Size(86, 23);
            this->lbl_Vnom->TabIndex = 92;
            this->lbl_Vnom->Text = L"48.000000";
            this->lbl_Vnom->Visible = false;
            //
            // lbl_cap
            //
            this->lbl_cap->AutoSize = true;
            this->lbl_cap->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->lbl_cap->Location = System::Drawing::Point(1646, 308);
            this->lbl_cap->Name = L"lbl_cap";
            this->lbl_cap->Size = System::Drawing::Size(95, 23);
            this->lbl_cap->TabIndex = 93;
            this->lbl_cap->Text = L"458.333344";
            this->lbl_cap->Visible = false;
            //
            // lbl_Npt
            //
            this->lbl_Npt->AutoSize = true;
            this->lbl_Npt->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->lbl_Npt->Location = System::Drawing::Point(1646, 222);
            this->lbl_Npt->Name = L"lbl_Npt";
            this->lbl_Npt->Size = System::Drawing::Size(22, 23);
            this->lbl_Npt->TabIndex = 94;
            this->lbl_Npt->Text = L"...";
            this->lbl_Npt->Visible = false;
            //
            // panel1
            //
            this->panel1->BackColor = System::Drawing::Color::MidnightBlue;
            this->panel1->Controls->Add(this->label4);
            this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
            this->panel1->Location = System::Drawing::Point(0, 0);
            this->panel1->Name = L"panel1";
            this->panel1->Size = System::Drawing::Size(1924, 76);
            this->panel1->TabIndex = 95;
            //
            // panel3
            //
            this->panel3->BackColor = System::Drawing::Color::MidnightBlue;
            this->panel3->Controls->Add(this->button4);
            this->panel3->Dock = System::Windows::Forms::DockStyle::Bottom;
            this->panel3->Location = System::Drawing::Point(0, 948);
            this->panel3->Name = L"panel3";
            this->panel3->Size = System::Drawing::Size(1924, 107);
            this->panel3->TabIndex = 97;
            //
            // button4
            //
            this->button4->BackColor = System::Drawing::Color::Gray;
            this->button4->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->button4->Location = System::Drawing::Point(1527, 17);
            this->button4->Name = L"button4";
            this->button4->Size = System::Drawing::Size(353, 41);
            this->button4->TabIndex = 118;
            this->button4->Text = L"Comzar estudio detallado";
            this->button4->UseVisualStyleBackColor = false;
            this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
            //
            // button2
            //
            this->button2->BackColor = System::Drawing::Color::Gray;
            this->button2->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->button2->Location = System::Drawing::Point(1165, 449);
            this->button2->Name = L"button2";
            this->button2->Size = System::Drawing::Size(170, 41);
            this->button2->TabIndex = 98;
            this->button2->Text = L"Actualizar valores";
            this->button2->UseVisualStyleBackColor = false;
            this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
            //
            // lbl_Imaxreg
            //
            this->lbl_Imaxreg->AutoSize = true;
            this->lbl_Imaxreg->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->lbl_Imaxreg->Location = System::Drawing::Point(1646, 505);
            this->lbl_Imaxreg->Name = L"lbl_Imaxreg";
            this->lbl_Imaxreg->Size = System::Drawing::Size(86, 23);
            this->lbl_Imaxreg->TabIndex = 28;
            this->lbl_Imaxreg->Text = L"27.264000";
            this->lbl_Imaxreg->Visible = false;
            //
            // button3
            //
            this->button3->BackColor = System::Drawing::Color::Gray;
            this->button3->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->button3->Location = System::Drawing::Point(41, 192);
            this->button3->Name = L"button3";
            this->button3->Size = System::Drawing::Size(100, 41);
            this->button3->TabIndex = 99;
            this->button3->Text = L"Cambiar ";
            this->button3->UseVisualStyleBackColor = false;
            this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
            //
            // label6
            //
            this->label6->AutoSize = true;
            this->label6->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label6->Location = System::Drawing::Point(35, 89);
            this->label6->Name = L"label6";
            this->label6->Size = System::Drawing::Size(225, 31);
            this->label6->TabIndex = 100;
            this->label6->Text = L"1. Método de diseño";
            //
            // lbl_tipo
            //
            this->lbl_tipo->AutoSize = true;
            this->lbl_tipo->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->lbl_tipo->Location = System::Drawing::Point(37, 151);
            this->lbl_tipo->Name = L"lbl_tipo";
            this->lbl_tipo->Size = System::Drawing::Size(81, 23);
            this->lbl_tipo->TabIndex = 101;
            this->lbl_tipo->Text = L"Peor Mes";
            //
            // lbl_ucap
            //
            this->lbl_ucap->AutoSize = true;
            this->lbl_ucap->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->lbl_ucap->Location = System::Drawing::Point(1763, 308);
            this->lbl_ucap->Name = L"lbl_ucap";
            this->lbl_ucap->Size = System::Drawing::Size(31, 23);
            this->lbl_ucap->TabIndex = 106;
            this->lbl_ucap->Text = L"Ah";
            this->lbl_ucap->Visible = false;
            //
            // lbl_uvnom
            //
            this->lbl_uvnom->AutoSize = true;
            this->lbl_uvnom->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->lbl_uvnom->Location = System::Drawing::Point(1763, 332);
            this->lbl_uvnom->Name = L"lbl_uvnom";
            this->lbl_uvnom->Size = System::Drawing::Size(21, 23);
            this->lbl_uvnom->TabIndex = 105;
            this->lbl_uvnom->Text = L"V";
            this->lbl_uvnom->Visible = false;
            //
            // lbl_uvmax
            //
            this->lbl_uvmax->AutoSize = true;
            this->lbl_uvmax->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->lbl_uvmax->Location = System::Drawing::Point(1763, 482);
            this->lbl_uvmax->Name = L"lbl_uvmax";
            this->lbl_uvmax->Size = System::Drawing::Size(21, 23);
            this->lbl_uvmax->TabIndex = 104;
            this->lbl_uvmax->Text = L"V";
            this->lbl_uvmax->Visible = false;
            //
            // lbl_uimax
            //
            this->lbl_uimax->AutoSize = true;
            this->lbl_uimax->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->lbl_uimax->Location = System::Drawing::Point(1763, 505);
            this->lbl_uimax->Name = L"lbl_uimax";
            this->lbl_uimax->Size = System::Drawing::Size(21, 23);
            this->lbl_uimax->TabIndex = 103;
            this->lbl_uimax->Text = L"A";
            this->lbl_uimax->Visible = false;
            //
            // lbl_upnom
            //
            this->lbl_upnom->AutoSize = true;
            this->lbl_upnom->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->lbl_upnom->Location = System::Drawing::Point(1763, 408);
            this->lbl_upnom->Name = L"lbl_upnom";
            this->lbl_upnom->Size = System::Drawing::Size(26, 23);
            this->lbl_upnom->TabIndex = 102;
            this->lbl_upnom->Text = L"W";
            this->lbl_upnom->Visible = false;
            //
            // label7
            //
            this->label7->AutoSize = true;
            this->label7->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label7->Location = System::Drawing::Point(1085, 394);
            this->label7->Name = L"label7";
            this->label7->Size = System::Drawing::Size(85, 23);
            this->label7->TabIndex = 114;
            this->label7->Text = L"Area [m  ]";
            //
            // label8
            //
            this->label8->AutoSize = true;
            this->label8->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 6, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label8->Location = System::Drawing::Point(1153, 393);
            this->label8->Name = L"label8";
            this->label8->Size = System::Drawing::Size(10, 12);
            this->label8->TabIndex = 115;
            this->label8->Text = L"2";
            //
            // tb_area
            //
            this->tb_area->Location = System::Drawing::Point(1266, 395);
            this->tb_area->Name = L"tb_area";
            this->tb_area->Size = System::Drawing::Size(174, 22);
            this->tb_area->TabIndex = 117;
            this->tb_area->Text = L"2.20";
            //
            // label10
            //
            this->label10->AutoSize = true;
            this->label10->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label10->Location = System::Drawing::Point(1487, 547);
            this->label10->Name = L"label10";
            this->label10->Size = System::Drawing::Size(235, 23);
            this->label10->TabIndex = 118;
            this->label10->Text = L"DESGLOSE DE LA INVERSIÓN";
            this->label10->Visible = false;
            //
            // rtb_1
            //
            this->rtb_1->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_1->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_1->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_1->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_1->Location = System::Drawing::Point(1487, 582);
            this->rtb_1->Name = L"rtb_1";
            this->rtb_1->ReadOnly = true;
            this->rtb_1->Size = System::Drawing::Size(157, 32);
            this->rtb_1->TabIndex = 201;
            this->rtb_1->Text = L"  Artículo o servicio";
            this->rtb_1->Visible = false;
            //
            // rtb_15
            //
            this->rtb_15->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_15->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_15->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_15->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_15->Location = System::Drawing::Point(1790, 582);
            this->rtb_15->Name = L"rtb_15";
            this->rtb_15->ReadOnly = true;
            this->rtb_15->Size = System::Drawing::Size(129, 32);
            this->rtb_15->TabIndex = 202;
            this->rtb_15->Text = L"        Coste";
            this->rtb_15->Visible = false;
            //
            // rtb_8
            //
            this->rtb_8->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_8->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_8->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_8->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_8->Location = System::Drawing::Point(1650, 582);
            this->rtb_8->Name = L"rtb_8";
            this->rtb_8->ReadOnly = true;
            this->rtb_8->Size = System::Drawing::Size(134, 32);
            this->rtb_8->TabIndex = 203;
            this->rtb_8->Text = L"     Unidades";
            this->rtb_8->Visible = false;
            //
            // rtb_9
            //
            this->rtb_9->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_9->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_9->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_9->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_9->Location = System::Drawing::Point(1650, 620);
            this->rtb_9->Name = L"rtb_9";
            this->rtb_9->ReadOnly = true;
            this->rtb_9->Size = System::Drawing::Size(134, 32);
            this->rtb_9->TabIndex = 206;
            this->rtb_9->Text = L"     Unidades";
            this->rtb_9->Visible = false;
            //
            // rtb_16
            //
            this->rtb_16->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_16->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_16->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_16->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_16->Location = System::Drawing::Point(1790, 620);
            this->rtb_16->Name = L"rtb_16";
            this->rtb_16->ReadOnly = true;
            this->rtb_16->Size = System::Drawing::Size(129, 32);
            this->rtb_16->TabIndex = 205;
            this->rtb_16->Text = L"        Coste";
            this->rtb_16->Visible = false;
            //
            // rtb_2
            //
            this->rtb_2->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_2->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_2->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_2->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_2->Location = System::Drawing::Point(1487, 620);
            this->rtb_2->Name = L"rtb_2";
            this->rtb_2->ReadOnly = true;
            this->rtb_2->Size = System::Drawing::Size(157, 32);
            this->rtb_2->TabIndex = 204;
            this->rtb_2->Text = L"          Paneles";
            this->rtb_2->Visible = false;
            //
            // rtb_10
            //
            this->rtb_10->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_10->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_10->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_10->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_10->Location = System::Drawing::Point(1650, 658);
            this->rtb_10->Name = L"rtb_10";
            this->rtb_10->ReadOnly = true;
            this->rtb_10->Size = System::Drawing::Size(134, 32);
            this->rtb_10->TabIndex = 209;
            this->rtb_10->Text = L"1";
            this->rtb_10->Visible = false;
            //
            // rtb_17
            //
            this->rtb_17->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_17->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_17->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_17->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_17->Location = System::Drawing::Point(1790, 658);
            this->rtb_17->Name = L"rtb_17";
            this->rtb_17->ReadOnly = true;
            this->rtb_17->Size = System::Drawing::Size(129, 32);
            this->rtb_17->TabIndex = 208;
            this->rtb_17->Text = L"        Coste";
            this->rtb_17->Visible = false;
            //
            // rtb_3
            //
            this->rtb_3->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_3->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_3->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_3->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_3->Location = System::Drawing::Point(1487, 658);
            this->rtb_3->Name = L"rtb_3";
            this->rtb_3->ReadOnly = true;
            this->rtb_3->Size = System::Drawing::Size(157, 32);
            this->rtb_3->TabIndex = 207;
            this->rtb_3->Text = L"  Inversor HUAWEI";
            this->rtb_3->Visible = false;
            //
            // rtb_11
            //
            this->rtb_11->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_11->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_11->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_11->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_11->Location = System::Drawing::Point(1650, 696);
            this->rtb_11->Name = L"rtb_11";
            this->rtb_11->ReadOnly = true;
            this->rtb_11->Size = System::Drawing::Size(134, 32);
            this->rtb_11->TabIndex = 212;
            this->rtb_11->Text = L"...";
            this->rtb_11->Visible = false;
            //
            // rtb_18
            //
            this->rtb_18->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_18->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_18->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_18->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_18->Location = System::Drawing::Point(1790, 696);
            this->rtb_18->Name = L"rtb_18";
            this->rtb_18->ReadOnly = true;
            this->rtb_18->Size = System::Drawing::Size(129, 32);
            this->rtb_18->TabIndex = 211;
            this->rtb_18->Text = L"        Coste";
            this->rtb_18->Visible = false;
            //
            // rtb_5
            //
            this->rtb_5->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_5->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_5->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_5->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_5->Location = System::Drawing::Point(1487, 734);
            this->rtb_5->Name = L"rtb_5";
            this->rtb_5->ReadOnly = true;
            this->rtb_5->Size = System::Drawing::Size(157, 32);
            this->rtb_5->TabIndex = 210;
            this->rtb_5->Text = L"      Instalación";
            this->rtb_5->Visible = false;
            //
            // rtb_12
            //
            this->rtb_12->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_12->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_12->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_12->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_12->Location = System::Drawing::Point(1650, 734);
            this->rtb_12->Name = L"rtb_12";
            this->rtb_12->ReadOnly = true;
            this->rtb_12->Size = System::Drawing::Size(134, 32);
            this->rtb_12->TabIndex = 215;
            this->rtb_12->Text = L"            -";
            this->rtb_12->Visible = false;
            //
            // rtb_19
            //
            this->rtb_19->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_19->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_19->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_19->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_19->Location = System::Drawing::Point(1790, 734);
            this->rtb_19->Name = L"rtb_19";
            this->rtb_19->ReadOnly = true;
            this->rtb_19->Size = System::Drawing::Size(129, 32);
            this->rtb_19->TabIndex = 214;
            this->rtb_19->Text = L"...";
            this->rtb_19->Visible = false;
            //
            // rtb_4
            //
            this->rtb_4->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_4->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_4->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_4->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_4->Location = System::Drawing::Point(1487, 696);
            this->rtb_4->Name = L"rtb_4";
            this->rtb_4->ReadOnly = true;
            this->rtb_4->Size = System::Drawing::Size(157, 32);
            this->rtb_4->TabIndex = 213;
            this->rtb_4->Text = L"  Soporte SolarBloc";
            this->rtb_4->Visible = false;
            //
            // rtb_13
            //
            this->rtb_13->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_13->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_13->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_13->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_13->Location = System::Drawing::Point(1650, 772);
            this->rtb_13->Name = L"rtb_13";
            this->rtb_13->ReadOnly = true;
            this->rtb_13->Size = System::Drawing::Size(134, 32);
            this->rtb_13->TabIndex = 218;
            this->rtb_13->Text = L"            -";
            this->rtb_13->Visible = false;
            //
            // rtb_20
            //
            this->rtb_20->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_20->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_20->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_20->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_20->Location = System::Drawing::Point(1790, 772);
            this->rtb_20->Name = L"rtb_20";
            this->rtb_20->ReadOnly = true;
            this->rtb_20->Size = System::Drawing::Size(129, 32);
            this->rtb_20->TabIndex = 217;
            this->rtb_20->Text = L"500";
            this->rtb_20->Visible = false;
            //
            // rtb_6
            //
            this->rtb_6->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_6->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_6->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_6->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_6->Location = System::Drawing::Point(1487, 772);
            this->rtb_6->Name = L"rtb_6";
            this->rtb_6->ReadOnly = true;
            this->rtb_6->Size = System::Drawing::Size(157, 32);
            this->rtb_6->TabIndex = 216;
            this->rtb_6->Text = L"      Ingenieria";
            this->rtb_6->Visible = false;
            //
            // rtb_14
            //
            this->rtb_14->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_14->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_14->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_14->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_14->Location = System::Drawing::Point(1650, 810);
            this->rtb_14->Name = L"rtb_14";
            this->rtb_14->ReadOnly = true;
            this->rtb_14->Size = System::Drawing::Size(134, 32);
            this->rtb_14->TabIndex = 221;
            this->rtb_14->Text = L"            -";
            this->rtb_14->Visible = false;
            //
            // rtb_21
            //
            this->rtb_21->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_21->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_21->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_21->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_21->Location = System::Drawing::Point(1790, 810);
            this->rtb_21->Name = L"rtb_21";
            this->rtb_21->ReadOnly = true;
            this->rtb_21->Size = System::Drawing::Size(129, 32);
            this->rtb_21->TabIndex = 220;
            this->rtb_21->Text = L"        Coste";
            this->rtb_21->Visible = false;
            //
            // rtb_7
            //
            this->rtb_7->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->rtb_7->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtb_7->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->rtb_7->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->rtb_7->Location = System::Drawing::Point(1487, 810);
            this->rtb_7->Name = L"rtb_7";
            this->rtb_7->ReadOnly = true;
            this->rtb_7->Size = System::Drawing::Size(157, 32);
            this->rtb_7->TabIndex = 219;
            this->rtb_7->Text = L"         TOTAL";
            this->rtb_7->Visible = false;
            //
            // lbl_esp
            //
            this->lbl_esp->AutoSize = true;
            this->lbl_esp->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->lbl_esp->Location = System::Drawing::Point(1646, 245);
            this->lbl_esp->Name = L"lbl_esp";
            this->lbl_esp->Size = System::Drawing::Size(22, 23);
            this->lbl_esp->TabIndex = 222;
            this->lbl_esp->Text = L"...";
            this->lbl_esp->Visible = false;
            //
            // label3
            //
            this->label3->AutoSize = true;
            this->label3->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label3->Location = System::Drawing::Point(1763, 245);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(25, 23);
            this->label3->TabIndex = 223;
            this->label3->Text = L"m";
            this->label3->Visible = false;
            //
            // label11
            //
            this->label11->AutoSize = true;
            this->label11->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 6, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label11->Location = System::Drawing::Point(1785, 245);
            this->label11->Name = L"label11";
            this->label11->Size = System::Drawing::Size(10, 12);
            this->label11->TabIndex = 224;
            this->label11->Text = L"2";
            this->label11->Visible = false;
            //
            // Form1
            //
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::Gainsboro;
            this->ClientSize = System::Drawing::Size(1924, 1055);
            this->Controls->Add(this->label11);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->lbl_esp);
            this->Controls->Add(this->rtb_14);
            this->Controls->Add(this->rtb_21);
            this->Controls->Add(this->rtb_7);
            this->Controls->Add(this->rtb_13);
            this->Controls->Add(this->rtb_20);
            this->Controls->Add(this->rtb_6);
            this->Controls->Add(this->rtb_12);
            this->Controls->Add(this->rtb_19);
            this->Controls->Add(this->rtb_4);
            this->Controls->Add(this->rtb_11);
            this->Controls->Add(this->rtb_18);
            this->Controls->Add(this->rtb_5);
            this->Controls->Add(this->rtb_10);
            this->Controls->Add(this->rtb_17);
            this->Controls->Add(this->rtb_3);
            this->Controls->Add(this->rtb_9);
            this->Controls->Add(this->rtb_16);
            this->Controls->Add(this->rtb_2);
            this->Controls->Add(this->rtb_8);
            this->Controls->Add(this->rtb_15);
            this->Controls->Add(this->rtb_1);
            this->Controls->Add(this->label10);
            this->Controls->Add(this->tb_area);
            this->Controls->Add(this->label8);
            this->Controls->Add(this->label7);
            this->Controls->Add(this->lbl_ucap);
            this->Controls->Add(this->lbl_uvnom);
            this->Controls->Add(this->lbl_uvmax);
            this->Controls->Add(this->lbl_uimax);
            this->Controls->Add(this->lbl_upnom);
            this->Controls->Add(this->lbl_tipo);
            this->Controls->Add(this->label6);
            this->Controls->Add(this->button3);
            this->Controls->Add(this->button2);
            this->Controls->Add(this->panel3);
            this->Controls->Add(this->panel1);
            this->Controls->Add(this->lbl_Npt);
            this->Controls->Add(this->lbl_cap);
            this->Controls->Add(this->lbl_Vnom);
            this->Controls->Add(this->lbl_Npp);
            this->Controls->Add(this->tb_precio);
            this->Controls->Add(this->label51);
            this->Controls->Add(this->tb_Voc);
            this->Controls->Add(this->tb_Isc);
            this->Controls->Add(this->label49);
            this->Controls->Add(this->label50);
            this->Controls->Add(this->tb_Imp);
            this->Controls->Add(this->tb_Pmp);
            this->Controls->Add(this->label46);
            this->Controls->Add(this->label47);
            this->Controls->Add(this->label48);
            this->Controls->Add(this->tb_Vmp);
            this->Controls->Add(this->label45);
            this->Controls->Add(this->tb_long);
            this->Controls->Add(this->tb_inclinacion);
            this->Controls->Add(this->tb_azimut);
            this->Controls->Add(this->label39);
            this->Controls->Add(this->label40);
            this->Controls->Add(this->label41);
            this->Controls->Add(this->label44);
            this->Controls->Add(this->tb_E12);
            this->Controls->Add(this->tb_E11);
            this->Controls->Add(this->tb_E3);
            this->Controls->Add(this->tb_E4);
            this->Controls->Add(this->tb_E5);
            this->Controls->Add(this->tb_E6);
            this->Controls->Add(this->tb_E7);
            this->Controls->Add(this->tb_E8);
            this->Controls->Add(this->tb_E9);
            this->Controls->Add(this->tb_E10);
            this->Controls->Add(this->label32);
            this->Controls->Add(this->label31);
            this->Controls->Add(this->label30);
            this->Controls->Add(this->label29);
            this->Controls->Add(this->label28);
            this->Controls->Add(this->label27);
            this->Controls->Add(this->label26);
            this->Controls->Add(this->label25);
            this->Controls->Add(this->label24);
            this->Controls->Add(this->label23);
            this->Controls->Add(this->label22);
            this->Controls->Add(this->label21);
            this->Controls->Add(this->lbl_Vmaxreg);
            this->Controls->Add(this->lbl_Imaxreg);
            this->Controls->Add(this->lbl_regd);
            this->Controls->Add(this->lbl_reg);
            this->Controls->Add(this->lbl_potinv);
            this->Controls->Add(this->lbl_invd);
            this->Controls->Add(this->lbl_inv);
            this->Controls->Add(this->lbl_batd);
            this->Controls->Add(this->lbl_Nps);
            this->Controls->Add(this->lbl_bat);
            this->Controls->Add(this->label12);
            this->Controls->Add(this->lbl_pand);
            this->Controls->Add(this->lbl_pan);
            this->Controls->Add(this->tb_potencia);
            this->Controls->Add(this->label5);
            this->Controls->Add(this->button1);
            this->Controls->Add(this->tb_lat);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->tb_E1);
            this->Controls->Add(this->tb_E2);
            this->Controls->Add(this->label1);
            this->Cursor = System::Windows::Forms::Cursors::Default;
            this->Name = L"Form1";
            this->Text = L"Form1";
            this->panel1->ResumeLayout(false);
            this->panel1->PerformLayout();
            this->panel3->ResumeLayout(false);
            this->ResumeLayout(false);
            this->PerformLayout();
        }
#pragma endregion
    //CODIGO EJECUTADO TRAS PRESIONAR EL BOTON DE CALCULAR
    private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
            int incmenos, incmas, prpaneles, prinversor, prsoporte, prinstalacion, pring, prtotal;
            float Emes[12] = { 0,0,0,0,0,0,0,0,0,0,0,0 }, Gmes[12] = { 0,0,0,0,0,0,0,0,0,0,0,0 };
            string sHSP, sEspacio,sPt,sNps, sNpp, sNpt, sCnombat, sVnom, sPinv, txtFloat;//DECLARACION DE VARIABLES PARA EL FUNCIONAMIENTO DEL TEXTO
            auto result = ValidateAndConvertInputs();  //TOMA LOS VALORES DELOS TEXTBOX CON UNA FUNCION
            string resultado;
            float lat, longitud, inclinacion, azimut,dist,distmin=9999999, pan_esp;        //SE INICIALIZA A ESE VALOR PARA ASEGURAR LA DISTANCIA MINIMA
            float Ecapitales[52][2] = //COORDENADAS DE LAS DIFERENTES CAPITALES DE PROVINCICA
            {
                {42.9,  -2.7},  //ALAVA
                {39.0,  -1.8},  //ALBACETE
                {38.4,  -0.5},  //ALICANTE
                {36.9,  -2.4},  //ALMERÍA
                {43.4,  -5.8},  //ASTURIAS
                {40.7,  -4.9},  //AVILA
                {38.9,  -7.0},  //BADAJOZ
                {39.6,  2.6},   //BALEARES
                {41.4,  2.2},   //BARCELONA
                {42.3,  -3.7},  //BURGOS
                {39.5,  -6.4},  //CÁCERES
                {36.5,  -6.3},  //CÁDIZ
                {43.5,  -3.8},  //CANTABRIA
                {40.0,  0.0},   //CASTELLÓN
                {35.9,  -5.3},  //CEUTA
                {39.0,  -3.9},  //CIUDAD REAL
                {37.9,  -4.8},  //CÓRDOBA
                {43.4,  -8.4},  //LA CORUÑA
                {40.1,  -2.1},  //CUENCA
                {42.0,  2.7},   //GIRONA
                {37.2,  -3.7},  //GRANADA
                {40.6,  -3.2},  //GUADALAJARA
                {43.3, -2.0},   //GUIPUZCOA
                {37.3,  -6.9},  //HUELVA
                {42.1,  -0.4},  //HUESCA
                {37.8,  -3.8},  //JAÉN
                {42.6,  -5.6},  //LEÓN
                {41.7,  1.2},   //LÉRIDA
                {43.0,  -7.6},  //LUGO
                {40.4,  -3.7},  //MADRID
                {36.7,  -4.4},  //MÁLAGA
                {35.3,  -3.0},  //MELILLA
                {38.0,  -1.1},  //MURCIA
                {42.8,  -1.6},  //NAVARRA
                {42.3,  -7.8},  //ORENSE
                {42.0,  -4.5},  //PALENCIA
                {28.2,  -15.4}, //LAS PALMAS
                {42.4,  -8.6},  //PONTEVEDRA
                {42.5,  -2.4},  //LA RIOJA
                {41.0,  -5.6},  //SALAMANCA
                {28.5,  -16.2}, //STA. C. DE TENERIFE
                {41.0,  -4.1},  //SEGOVIA
                {37.4,  -6.0},  //SEVILLA
                {41.8,  -2.5},  //SORIA
                {41.1,  1.2},   //TARRAGONA
                {40.4,  -1.1},  //TERUEL
                {39.9,  -4.0},  //TOLEDO
                {39.5,  -0.4},  //VALENCIA
                {41.7,  -4.7},  //VALLADOLID
                {43.3,  -3.0},  //VIZCAYA
                {41.5,  -5.7},  //ZAMORA
                {41.7,  -0.9}   //ZARAGOZA
            };
            float datos_inv[7][2] = {
                { 2000,676.40 },        //PRECIOS ACTUALIZADOS 23/11/23 EN "AUTOSOLAR"
                { 3000,796.88 }, { 4000,973.60 }, { 5000,1057.15 }, { 6000,1232.54 }, { 10000,2820.95 }, { 20000,3151.71 }
            };
            int pos_inv;
            string nom_inv[7] = { "SUN2000_2KTL_L1","SUN2000_3KT_L1","SUN2000_4KTL_L1","SUN2000_5KTL_L1","SUN2000_6KTL_L1","SUN2000_10KTL_M1","SUN2000_2KTL_M2"};
            float datos_bat;
            int horamin, horamax;//variables para comprobar si esta dentro ofuera de las horas de pico
            bool ok = get<0>(result);
            Emes[0] = get<1>(result);
            Emes[1] = get<2>(result);
            Emes[2] = get<3>(result);
            Emes[3] = get<4>(result);
            Emes[4] = get<5>(result);
            Emes[5] = get<6>(result);
            Emes[6] = get<7>(result);
            Emes[7] = get<8>(result);
            Emes[8] = get<9>(result);
            Emes[9] = get<10>(result);
            Emes[10] = get<11>(result);
            Emes[11] = get<12>(result);
            lat= get<13>(result);
            longitud = get<14>(result);
            inclinacion = get<15>(result);
            azimut = get<16>(result);
            float Pt = get<17>(result);
            if (ok) {   //COMPRUEBA SI LOS DATOS INTRODUCIDOS SON CORRECTOS
                std::string rutaArchivo = obtenerRutaRelativaArchivo();
                rutaArchivo = rutaArchivo + "//Factor_Correccion_PCT.txt";
                incmenos = inclinacion;
                incmas = inclinacion;
                while (incmenos % 5 != 0 && incmas % 5 != 0) {  //SE BUSCA LA INCLINACION MAS PROXIMA A LA SELECCIONADA MULTIPLOS DE5 EN FUNCIÓN DE LOS DATOS DEL FICHERO
                    incmenos = incmenos - 1;
                    incmas = incmas + 1;
                }
                int incentero, latentero;
                if (incmas % 5 == 0) incentero = incmas;
                else incentero = incmenos;
                latentero = lat;
                string sinc = to_string(incentero);
                string slat = to_string(latentero);
                std::string terminoBuscado = slat+sinc; //LA INCLINACION Y LATITUD INTRODUCIDAS SE CODIFICAN PARA BUSCAR EN EL FICHERO Y CALCULAR LAS PERDIDAS DE G
                for (size_t i = 0; i < rutaArchivo.length(); i++)
                {
                    if (rutaArchivo[i] == '\\')
                    {
                        rutaArchivo.replace(i, 1, "//");
                        i++;  // Avanzar un índice adicional para evitar reemplazar el siguiente carácter '/'
                    }
                }
                std::vector<std::string> lineasEncontradas = buscarTerminoEnArchivo(rutaArchivo, terminoBuscado);
                if (lineasEncontradas.size() < 13) { //NO HAY DATOS PARA ESA LATITUD (EL FICHERO SOLO TIENE 28,29 Y 34-45)
                    MessageBox::Show(L"No hay factores de correccion para la latitud introducida (disponibles: 28, 29 y 34 a 45).");
                    return;
                }
                for (int i = 1; i <= 12; i++) {
                    resultado = intercambiarComasPorPuntos(lineasEncontradas[i]); //ES NECESARIO CAMBIAR COMAS POR PUNTOS PARA QUE FUNCIONE CORRECTAMENTE EL BUSCADOR DEL FICHERO
                    Gmes[i-1] = stof(resultado);
                }
                //EXTRAER VALOR DEL FICHERO DE IRRADIANCIA MEDIA EN LAS CAPITALES DE PROVINCIA MAS PRÓXIMAS
                rutaArchivo = obtenerRutaRelativaArchivo();
                rutaArchivo = rutaArchivo + "//Capitales_V2.txt";
                double latfinal, longfinal;
                int capital;
                for (int i = 0; i < 52; i++) {  //COMPRUEBA LA DISTANCIA MINIMA, DATOS DE USUARIO EN lat/longitud, LAS LONGITUDES DE TODAS LAS CAPITALES DE PROVINCIA
                    latfinal = pow((lat - Ecapitales[i][0]), 2); //SE CALCULA UTILIZANDO: RAIZ(LAT^2+LONG^2)
                    longfinal = pow((longitud - Ecapitales[i][1]), 2);
                    dist = sqrt(latfinal+longfinal);
                    if (dist < distmin) {
                        distmin = dist;
                        capital = i;
                    }
                }
                int numabuscar;
                numabuscar = Ecapitales[capital][0] * 1000 - Ecapitales[capital][1] * 10; //SE REALIZAN ESOS CALCULOS PORQUE EL FICHERO SE HA CODIFICADO SIGUIENDO ESAS OPERACIONES
                for (size_t i = 0; i < rutaArchivo.length(); i++)
                {
                    if (rutaArchivo[i] == '\\')
                    {
                        rutaArchivo.replace(i, 1, "//");
                        i++;  // Avanzar un índice adicional para evitar reemplazar el siguiente carácter '/'
                    }
                }
                lineasEncontradas = buscarTerminoEnArchivo(rutaArchivo, to_string(numabuscar));
                if (lineasEncontradas.size() < 13) {
                    MessageBox::Show(L"No se encontraron datos de irradiacion en Capitales_V2.txt.");
                    return;
                }
                float valorfichero, perdidasorientacion; //SE REÚNEN LOS DATOS DEL FICHERO Y CON LA FÓRMULA (X) SE CALCULAN LOS PÉRDIDAS POR ORIENTACIÓN E INCLINACIÓN
                azimut = pow(azimut, 2);
                perdidasorientacion = azimut * 3.5 * 0.00001;
                for (int i = 1; i <= 12; i++) {
                    resultado= intercambiarComasPorPuntos(lineasEncontradas[i]);
                    valorfichero= stof(resultado);
                    Gmes[i - 1] = Gmes[i - 1] * valorfichero*(1- perdidasorientacion);
                }
                if (tipo) {     //SE COMPARA SI EL CALCULO SE VA A REALIZAREN FORMA DE AUTOCONSUMO (METODO PEOR MES) O CONECTADO A RED (IRRADIANCIA MEDIA) SEGÚN BOTON 2
                    for (int i=0; i < 12; i++) {
                        auxnum = Emes[i]/ Gmes[i];
                        if (auxnum > Etmedio) {
                            Etmedio = Emes[i]*1000/31;
                            HSP = Gmes[i];
                        }
                    }
                }
                else {  //SE COMPARA SI EL CALCULO SE VA A REALIZAR EN FORMADE AUTOCONSUMO (METODO PEOR MES) O ENCHUFADO A RED(IRRADIANCIA MEDIA) SEGÚN BOTON 2
                    for (int i = 0; i < 12; i++) Etmedio = Etmedio + Emes[i] *1000;
                    Etmedio = Etmedio / 365;
                    //Etmedio = (Emes[0] * 31 + Emes[1] * 28 + Emes[2] * 31 + Emes[3] * 30 + Emes[4] * 31 + Emes[5] * 30 + Emes[6] * 31 + Emes[7] * 31 + Emes[8] * 30 + Emes[9] * 31 + Emes[10] * 30 + Emes[11] * 31) / 365;
                    HSP = (Gmes[0] * 31 + Gmes[1] * 28 + Gmes[2] * 31 + Gmes[3] * 30 + Gmes[4] * 31 + Gmes[5] * 30 + Gmes[6] * 31 + Gmes[7] * 31 + Gmes[8] * 30 + Gmes[9] * 31 + Gmes[10] * 30 + Gmes[11] * 31) / 365;
                }
                if (Pt < 800)   Vnom = 12;      //se asigna la tension nominal dependiendo de la potencia requerida
                else if (Pt < 1600) Vnom = 24;
                else if (Pt < 3200) Vnom = 48;
                else Vnom = 120;
                Ctmax = (Etmedio / Vnom) / kt;
                Epanel = npanel * HSP * Pm;     //CALCULAMOS LA DEMANDA PORPANEL
                //MessageBox::Show(this->toSystemString(to_string(Epanel)));
                //MessageBox::Show(this->toSystemString(to_string(Ctmax)));
                auxnum = Vnom / Vm;             //Utilizamos auxnum porque es un "float"
                Nps = auxnum;
                if (auxnum - Nps > 0.2) Nps++;
                auxnum = (Ctmax * Vnom) / Epanel;
                Npt = auxnum;
                if (auxnum - Npt > 0.2) Npt++;
                if (Npt < Nps) Npt = Nps;
                /* auxnum = espacio / areapanel; //COMPROBACION DE LA CANTIDADDE PLACAS QUE ENTRAN FISICAMENTE
                if (auxnum < Npt) {
                    Npt = auxnum;       //NOS QUEDAMOS CON EL VALOR MAS RESTRICTIVO (PROBLEMAS CON EL SOMBREADO CAUSADO POR LAS PLACAS Y DIFERENTES FORMAS DE TERRAZA)
                }
                */ while (Npt%Nps!=0) Npt++;
                Npp = Npt / Nps;
                por = (autonum / Etotal) * 100;
                pan_esp = areapanel * Npt;
                //Dimensionado batería
                Cnombat = (Ctmax * Daut) / Pdmax;
                //Dimensionado del regulador
                Vinmax = 1.1 * Nps * Voc;
                Iinmax = 1.2 * Npp * Isc;
                //Dimensionado del inversor
                Pinv = Pt / ninv;
                if (Npt * Pm * 1.5 > Pinv) Pinv = Npt * Pm; //SE COMPRUEBA QUE EL INVERSOR SEA CAPAZ DE ACEPTAR LA POTENCIA PICO DE ENTRADA
                //LA COMPROBACIÓN DE LA CORRIENTE Y TENSION MAXIMAS DEPENDENDE LAS DISTRIBUCIONES DE STRINGS EN LAS ENTRADAS DE LOS MPPT, POSIBLE MEJORA
                //Calculo de precios
                prpaneles = Npt * prpan;
                int aux_inv = 0,Ninv;
                bool inv_check = false;     //ASEGURA QUE SE HAYA ELEGIDO UNINVERSOR
                while (!inv_check) {
                    for (int i = 0; i < 7; i++) {
                        if (Pinv < datos_inv[i][0] + aux_inv * datos_inv[6][0]&&!inv_check) { //COMPRUEBA CUAL ES LA COMBINACIÓN DEINVERSORES MINIMA PARA HACER FUNCIONAR EL PROGRAMA
                            pos_inv = i;
                            inv_check = true;
                        }
                    }
                    if (!inv_check) aux_inv++;
                }
                prinversor = datos_inv[pos_inv][1] + aux_inv * datos_inv[6][1];
                Ninv = 1 + aux_inv;
                prsoporte = Npt*20;
                prinstalacion = Npt*100; //Hay que mirarlo
                if (Pinv > 10000) pring = 1000;
                else pring = 500;
                prtotal = prpaneles + prinversor + prsoporte + prinstalacion + pring;
                //Mostrar los resultados TEXTO
                this->lbl_pan->Visible = true;
                this->lbl_pand->Visible = true;
                this->lbl_bat->Visible = true;
                this->lbl_batd->Visible = true;
                this->lbl_inv->Visible = true;
                this->lbl_invd->Visible = true;
                this->lbl_reg->Visible = true;
                this->lbl_regd->Visible = true;
                this->lbl_ucap->Visible = true;
                this->lbl_uvnom->Visible = true;
                this->lbl_upnom->Visible = true;
                this->lbl_uvmax->Visible = true;
                this->lbl_uimax->Visible = true;
                this->lbl_uimax->Visible = true;
                this->label10->Visible = true;
                this->label12->Visible = true;
                this->label3->Visible = true;
                this->label11->Visible = true;
                //SE MUESTRAN LOS RESULTADOS CALCULADOS this->lbl_Nps->Visible = true;
                lbl_Nps->Text = gcnew System::String(to_string(Nps).c_str());
                this->lbl_Npp->Visible = true;
                lbl_Npp->Text = gcnew System::String(to_string(Npp).c_str());
                this->lbl_Npt->Visible = true;
                lbl_Npt->Text = gcnew System::String(to_string(Npt).c_str());
                this->lbl_esp->Visible = true;
                lbl_esp->Text = gcnew System::String(to_string(pan_esp).c_str());
                this->lbl_cap->Visible = true;
                lbl_cap ->Text = gcnew System::String(to_string(Cnombat).c_str());
                this->lbl_Vnom->Visible = true;
                lbl_Vnom->Text = gcnew System::String(to_string(Vnom).c_str());
                this->lbl_potinv->Visible = true;
                lbl_potinv->Text = gcnew System::String(to_string(Pinv).c_str());
                this->lbl_Vmaxreg->Visible = true;
                lbl_Vmaxreg->Text = gcnew System::String(to_string(Vinmax).c_str());
                this->lbl_Imaxreg->Visible = true;
                lbl_Imaxreg->Text = gcnew System::String(to_string(Iinmax).c_str());
                //SE MUESTRAN LOS RESULTADOS DE LA INVERSION this->rtb_1->Visible = true;
                this->rtb_2->Visible = true;
                this->rtb_3->Visible = true;
                this->rtb_4->Visible = true;
                this->rtb_5->Visible = true;
                this->rtb_6->Visible = true;
                this->rtb_7->Visible = true;
                this->rtb_8->Visible = true;
                this->rtb_9->Visible = true;
                rtb_9->Text = gcnew System::String(to_string(Npt).c_str());
                this->rtb_10->Visible = true;
                rtb_10->Text = gcnew System::String(to_string(Ninv).c_str());
                this->rtb_11->Visible = true;
                rtb_11->Text = gcnew System::String(to_string(Npt).c_str());
                this->rtb_12->Visible = true;
                this->rtb_13->Visible = true;
                this->rtb_14->Visible = true;
                this->rtb_15->Visible = true;
                this->rtb_16->Visible = true;
                rtb_16->Text = gcnew System::String(to_string(prpaneles).c_str());
                this->rtb_17->Visible = true;
                rtb_17->Text = gcnew System::String(to_string(prinversor).c_str());
                this->rtb_18->Visible = true;
                rtb_18->Text = gcnew System::String(to_string(prsoporte).c_str());
                this->rtb_19->Visible = true;
                rtb_19->Text = gcnew System::String(to_string(prinstalacion).c_str());
                this->rtb_20->Visible = true;
                rtb_20->Text = gcnew System::String(to_string(pring).c_str());
                this->rtb_21->Visible = true;
                rtb_21->Text = gcnew System::String(to_string(prtotal).c_str());
                Etmedio = 0;
                HSP = 0;
                Nps = 0;
            }
    }
     //CONVIERTE VARIABLES DEL SISTEMA EN STRINGS
    private: static string toStandardString(System::String^ string)     {
            using System::Runtime::InteropServices::Marshal;
            System::IntPtr pointer = Marshal::StringToHGlobalAnsi(string);
            char* charPointer = reinterpret_cast<char*>(pointer.ToPointer());
            std::string returnString(charPointer, string->Length);
            Marshal::FreeHGlobal(pointer);
            return returnString;
        }
        //CONVIERTE STRINGS A VARIABLES DEL SISTEMA
        private: static String^ toSystemString(string str) {
            return gcnew String(str.c_str());
        }
        private: bool esNumerico(string texto) {
            if (texto.length() == 0) {
                return false;
            }
            bool decimalEncontrado = false;
            bool negativoEncontrado = false;
            for (char c : texto) {
                if (isdigit(c)) {
                    continue;
                }
                else if ((c == '.' || c == ',') && !decimalEncontrado) {
                    decimalEncontrado = true;
                    continue;
                }
                else if (c == '-' && !negativoEncontrado) {
                    negativoEncontrado = true;
                    continue;
                }
                else {
                    return false;
                }
            }
            return true;
        }
        // CAMBIA LAS COMAS POR LOS PUNTOS
        std::string intercambiarComasPorPuntos(const std::string& str) {
            std::string resultado = str;
            for (char& c : resultado) {
                if (c == ',') {
                    c = '.';
                }
            }
            return resultado;
        }
            // BUSCA TERMNIOS EN UN FICHERO
           std::vector<std::string> buscarTerminoEnArchivo(std::string& rutaArchivo, const std::string& terminoBuscado)
           {
               std::ifstream archivo(rutaArchivo);
               std::vector<std::string> lineasEncontradas;
               if (archivo.is_open()) {
                   std::string linea;
                   while (std::getline(archivo, linea)) {
                       // Lógica para buscar el término en la línea
                       if (linea.compare(0, terminoBuscado.length() + 1, terminoBuscado + "\t") == 0) {
                           std::istringstream iss(linea);
                           std::string termino;
                           while (std::getline(iss, termino, '\t')) {
                               lineasEncontradas.push_back(termino);
                           }
                       }
                   }
                   archivo.close();
               }
               return lineasEncontradas;
           }
           // OBTIENE LA RUTA EN LA QUE SE ENCUENTRA EL .EXE
           std::string obtenerRutaRelativaArchivo()
           {
               String^ rutaEnsamblado = Assembly::GetExecutingAssembly()->Location;
               String^ rutaDirectorio = Path::GetDirectoryName(rutaEnsamblado);
               std::string rutaRelativa = toStandardString(rutaDirectorio);
               return rutaRelativa;
           }
    //FUNCIÓN PARA OBTENER LOS DATOS DE LOS DIFERENTES TEXTBOX
    private: tuple<bool, float, float, float,  float, float, float, float, float, float, float, float, float, float, float, float, float, float> ValidateAndConvertInputs()
    {
        bool ok = true;
        float E1, E2, E3, E4, E5, E6, E7, E8, E9, E10, E11, E12;
        float G1, G2, G3, G4;
        float Pt;
        string sE1, sE2, sE3, sE4, sE5, sE6, sE7, sE8, sE9, sE10, sE11, sE12;
        string sG1, sG2, sG3, sG4, sG5, sG6, sG7, sG8, sG9, sG10, sG11, sG12;
        string sPt, error = "Error introduciendo los siguientes datos: \n";
        // Validación y conversión del consumo de enero
        sE1 = this->toStandardString(this->tb_E1->Text);
        if (!esNumerico(sE1)) {
            error = error + "Consumo de enero \n";
            ok = false;
        }
        else {
            E1 = stof(sE1);
        }
        sE2 = this->toStandardString(this->tb_E2->Text);
        if (!esNumerico(sE2)) {
            error = error + "Consumo de febrero \n";
            ok = false;
        }
        else {
            E2 = stof(sE2);
        }
        sE3 = this->toStandardString(this->tb_E3->Text);
        if (!esNumerico(sE3)) {
            error = error + "Consumo de marzo \n";
            ok = false;
        }
        else {
            E3 = stof(sE3);
        }
        sE4 = this->toStandardString(this->tb_E4->Text);
        if (!esNumerico(sE4)) {
            error = error + "Consumo de abril \n";
            ok = false;
        }
        else {
            E4 = stof(sE4);
        }
        sE5 = this->toStandardString(this->tb_E5->Text);
        if (!esNumerico(sE5)) {
            error = error + "Consumo de mayo \n";
            ok = false;
        }
        else {
            E5 = stof(sE5);
        }
        sE6 = this->toStandardString(this->tb_E6->Text);
        if (!esNumerico(sE6)) {
            error = error + "Consumo de junio \n";
            ok = false;
        }
        else {
            E6 = stof(sE6);
        }
        sE7 = this->toStandardString(this->tb_E7->Text);
        if (!esNumerico(sE7)) {
            error = error + "Consumo de julio \n";
            ok = false;
        }
        else {
            E7 = stof(sE7);
        }
        sE8 = this->toStandardString(this->tb_E8->Text);
        if (!esNumerico(sE8)) {
            error = error + "Consumo de agosto \n";
            ok = false;
        }
        else {
            E8 = stof(sE8);
        }
        sE9 = this->toStandardString(this->tb_E9->Text);
        if (!esNumerico(sE9)) {
            error = error + "Consumo de septiembre \n";
            ok = false;
        }
        else {
            E9 = stof(sE9);
        }
        sE10 = this->toStandardString(this->tb_E10->Text);
        if (!esNumerico(sE10)) {
            error = error + "Consumo de octubre \n";
            ok = false;
        }
        else {
            E10 = stof(sE10);
        }
        sE11 = this->toStandardString(this->tb_E11->Text);
        if (!esNumerico(sE11)) {
            error = error + "Consumo de noviembre \n";
            ok = false;
        }
        else {
            E11 = stof(sE11);
        }
        sE12 = this->toStandardString(this->tb_E12->Text);
        if (!esNumerico(sE12)) {
            error = error + "Consumo de diciembre \n";
            ok = false;
        }
        else {
            E12 = stof(sE12);
        }
        // Validación y conversión de la irradiancia
        sG1 = this->toStandardString(this->tb_lat->Text);
        if (!esNumerico(sG1)) {
            error = error + "Latitud \n";
            ok = false;
        }
        else {
            G1 = stof(sG1);
            if (G1 > 45) {
                ok = false;
                error = error + "Latitud\n";
            }
            if (G1 < 25) {
                ok = false;
                error = error + "Latitud\n";
            }
        }
        sG2 = this->toStandardString(this->tb_long->Text);
        if (!esNumerico(sG2)) {
            error = error + "Longitud \n";
            ok = false;
        }
        else {
            G2 = stof(sG2);
            if (G2 > 5) {
                ok = false;
                error = error + "Longitud\n";
            }
            if (G2 < -19) {
                ok = false;
                error = error + "Longitud\n";
            }
        }
        sG3 = this->toStandardString(this->tb_inclinacion->Text);
        if (!esNumerico(sG3)) {
            error = error + "Inlcinacion \n";
            ok = false;
        }
        else {
            G3 = stof(sG3);
        }
        sG4 = this->toStandardString(this->tb_azimut->Text);
        if (!esNumerico(sG4)) {
            error = error + "Azimut \n";
            ok = false;
        }
        else {
            G4 = stof(sG4);
        }
        // Validación y conversión de la potencia
        sPt = this->toStandardString(this->tb_potencia->Text);
        if (!esNumerico(sPt)) {
            error = error + "Potencia \n";
            ok = false;
        }
        else {
            Pt = stof(sPt);
        }
        if (ok == false) {
            MessageBox::Show(this->toSystemString(error));
        }
        return make_tuple(ok, E1, E2, E3, E4, E5, E6, E7, E8, E9, E10, E11, E12, G1, G2, G3, G4, Pt);
    }
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
    string sPmp, sVoc, sIsc, sVmp, sImp, sprecio,sarea,error="Error introduciendo:\n";
    bool ok=true;
    sVmp = this->toStandardString(this->tb_Vmp->Text);
    if (!esNumerico(sVmp)) {
        error = error + "Vmp \n";
        ok = false;
    }
    else {
        Vm = stof(sVmp);
    }
    sImp = this->toStandardString(this->tb_Imp->Text);
    if (!esNumerico(sImp)) {
        error = error + "Imp \n";
        ok = false;
    }
    else {
        Im = stof(sImp);
    }
    sPmp = this->toStandardString(this->tb_Pmp->Text);
    if (!esNumerico(sPmp)) {
        error = error + "Potencia \n";
        ok = false;
    }
    else {
        Pm = stof(sPmp);
    }
    sVoc = this->toStandardString(this->tb_Voc->Text);
    if (!esNumerico(sVoc)) {
        error = error + "Voc \n";
        ok = false;
    }
    else {
        Voc = stof(sVoc);
    }
    sIsc = this->toStandardString(this->tb_Isc->Text);
    if (!esNumerico(sIsc)) {
        error = error + "Isc \n";
        ok = false;
    }
    else {
        Isc = stof(sIsc);
    }
    sprecio = this->toStandardString(this->tb_precio->Text);
    if (!esNumerico(sprecio)) {
        error = error + "Precio \n";
        ok = false;
    }
    else {
        prpan = stof(sprecio);
    }
    sarea = this->toStandardString(this->tb_area->Text);
    if (!esNumerico(sarea)) {
        error = error + "Area \n";
        ok = false;
    }
    else {
        prpan = stof(sarea);
    }
    if (ok == false) {
        MessageBox::Show(this->toSystemString(error));
    }
    else MessageBox::Show(L"Valores actualizados");
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
    if (tipo) {
        this->lbl_tipo->Text = "Promedio mensual";
        tipo = false;
    }
    else {
        this->lbl_tipo->Text = "Peor mes";
        tipo = true;
    }
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
        //FORMA DE ABRIR OTRO FORMULARIO
        Prueba1::Resultado^ resultado = gcnew Prueba1::Resultado();
        resultado->SetBounds(0, 0, Screen::PrimaryScreen->Bounds.Width, Screen::PrimaryScreen->Bounds.Height);
        this->Visible = false;
        resultado->ShowDialog();
        this->Visible = true;
}
};
}
