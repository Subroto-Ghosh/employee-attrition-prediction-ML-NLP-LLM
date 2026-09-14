# Employee Attrition Prediction Using Machine Learning, NLP, and Large Language Models

**CSE445 — Machine Learning Project**
North South University · Supervisor: **Dr. Riasat Khan** (Associate Professor)

Authors: **Subroto Ghosh** (2212150642) · **Joy Saha Ayon** (2312466042)

An academic machine learning project for employee attrition prediction using classical machine learning, transformer-based Natural Language Processing (NLP), and Large Language Models (LLMs).

## Abstract

Employee attrition prediction is a binary classification task that aims to identify employees who may leave an organization. This project investigates multiple modeling approaches on the IBM HR Analytics Employee Attrition & Performance dataset, including classical machine learning algorithms, ensemble learning, transformer-based NLP models, and LLM-based approaches. The study also examines class-imbalance handling, threshold selection, text augmentation, explainability, and ablation analysis.

The reported results show that the Stacking Ensemble achieved the highest test F1-score among the evaluated classical approaches, while TinyLlama achieved the highest reported F1-score among the evaluated NLP/LLM models.

> **Academic note:** This repository preserves the supplied project notebooks and reported results. A split-description inconsistency between parts of the report and the NLP notebook is documented in `docs/REPRODUCIBILITY.md`.

---

## Project Objectives

The project has the following objectives:

1. Develop classical machine learning models for employee attrition prediction.
2. Investigate the effect of class-imbalance handling using SMOTE and alternative sampling methods.
3. Improve predictive performance through hyperparameter tuning and ensemble learning.
4. Convert tabular employee records into natural-language representations for NLP and LLM-based modeling.
5. Compare transformer-based models with classical machine learning approaches.
6. Analyze model behavior using explainability techniques.
7. Evaluate the contribution of major pipeline components through ablation analysis.

---

## Dataset

The project uses the **IBM HR Analytics Employee Attrition & Performance** dataset.

| Property                 |       Value |
| ------------------------ | ----------: |
| Employee records         |       1,470 |
| Raw attributes           |          35 |
| Attrition-positive cases |         237 |
| Attrition rate           |      ~16.1% |
| Target variable          | `Attrition` |

The dataset is **not included in this repository**. Dataset acquisition instructions are provided in [`data/README.md`](data/README.md).

---

## Methodology

### 1. Data Preprocessing

The classical machine learning pipeline includes:

- Removal of identifier and constant columns
- IQR-based outlier winsorization
- Correlation and VIF analysis
- Log transformation of selected skewed financial variables
- Label encoding for selected binary categorical variables
- One-hot encoding for multi-class categorical variables
- Feature scaling
- Stratified train/validation/test splitting

### 2. Class Imbalance Handling

Because the dataset contains substantially fewer attrition-positive cases, class-imbalance techniques were evaluated. For the classical pipeline, SMOTE is applied **inside the cross-validation pipeline** to reduce the risk of data leakage.

Alternative sampling strategies were also compared, including:

- Borderline-SMOTE
- ADASYN
- SMOTE
- SMOTETomek
- RandomOverSampler

### 3. Classical Machine Learning

The following models were evaluated:

- Decision Tree
- Logistic Regression
- RBF Support Vector Machine
- Random Forest
- Gradient Boosting

Hyperparameter optimization was performed using **5-fold GridSearchCV**.

### 4. Ensemble Learning

Two ensemble strategies were investigated:

- **Stacking Ensemble:** Decision Tree, Logistic Regression, and Gradient Boosting as base learners with Logistic Regression as the meta-learner.
- **Blending Ensemble:** the same base models combined using a weighted prediction strategy.

### 5. NLP and LLM Modeling

Each tabular employee record was serialized into a natural-language representation. The following models were evaluated:

- DistilBERT
- BERT-base
- Flan-T5-base
- TinyLlama-1.1B

The supplied NLP notebook uses a 70/15/15 train/validation/test split and applies training-only upsampling. Details are documented in `docs/REPRODUCIBILITY.md`.

### 6. Threshold Selection

For the reported classical test evaluation, decision thresholds are selected using validation data and then kept fixed for final test evaluation.

### 7. Explainable AI

The project investigates model interpretation using:

- SHAP
- LIME
- Feature permutation importance

The reported permutation-importance analysis identifies **OverTime** as the strongest feature, with an importance value of **0.1093**.

### 8. Ablation Analysis

The project evaluates the contribution of major components by removing selected elements from the full pipeline, including ensembling, hyperparameter tuning, and SMOTE.

---

## Reported Results

### Best Classical Model

The **Stacking Ensemble** achieved the highest reported test F1-score among the classical approaches.

| Metric    |  Score |
| --------- | -----: |
| Accuracy  | 85.93% |
| Precision | 0.5254 |
| Recall    | 0.6596 |
| F1-score  | 0.5849 |
| ROC-AUC   | 0.7989 |

The Blending Ensemble achieved a slightly higher accuracy of **86.05%**, whereas Stacking achieved the higher F1-score and recall.

### NLP / LLM Results

Among the evaluated NLP/LLM models, **TinyLlama-1.1B** achieved the highest reported F1-score (**0.4507**) and ROC-AUC (**0.7995**).

### Ablation Results

| Configuration                 | Test F1-score |
| ----------------------------- | ------------: |
| Full configuration            |        0.5849 |
| Without ensembling            |        0.5120 |
| Without hyperparameter tuning |        0.4792 |
| Without SMOTE                 |        0.4462 |

The reported results indicate a substantial performance reduction when major components of the full pipeline are removed.

---

## Repository Structure

```text
employee-attrition-prediction-ml-nlp-llm/
│
├── README.md
├── LICENSE
├── requirements.txt
├── .gitignore
│
├── notebooks/
│   ├── 01_full_ml_nlp_llm_pipeline.ipynb
│   └── 02_nlp_llm_pipeline.ipynb
│
├── data/
│   └── README.md
│
├── results/
│   ├── classical_default_cv_results.csv
│   ├── locked_threshold_test_results.csv
│   ├── nlp_llm_test_results.csv
│   ├── sampler_comparison.csv
│   ├── text_augmentation_results.csv
│   ├── ablation_results.csv
│   ├── distilbert_training_dynamics.csv
│   ├── feature_permutation_importance.csv
│   └── figures/
│
├── report/
│   └── CSE445_Project_Report.pdf
│
├── presentation/
│   └── CSE445_Project_Proposal.pptx
│
└── docs/
    ├── REPRODUCIBILITY.md
    └── RESULTS_SUMMARY.md
```

---

## Installation

The classical experiments can be run in a standard Python environment. Transformer and LLM experiments may require substantially more computational resources.

```bash
git clone <YOUR-GITHUB-REPOSITORY-URL>
cd employee-attrition-prediction-ml-nlp-llm
python -m venv .venv
```

Activate the virtual environment and install the dependencies:

### Windows

```bash
.venv\\Scripts\\activate
pip install -r requirements.txt
```

### Linux / macOS

```bash
source .venv/bin/activate
pip install -r requirements.txt
```

---

## Usage

### Classical Machine Learning

Open:

```text
notebooks/01_full_ml_nlp_llm_pipeline.ipynb
```

Place the dataset CSV in the notebook working directory and execute the notebook sequentially.

### NLP / LLM Experiments

Open:

```text
notebooks/02_nlp_llm_pipeline.ipynb
```

A GPU-enabled environment such as Google Colab is recommended for transformer and LLM fine-tuning.

> The notebooks may download pretrained model components and therefore require an appropriate internet connection and sufficient storage/RAM/GPU resources.

---

## Reproducibility

The repository follows the evaluation protocol implemented in the supplied project materials. In particular:

- The final test data are kept separate from training operations.
- SMOTE is applied within the classical cross-validation pipeline.
- Validation data are used for threshold selection.
- The selected threshold is then locked before test evaluation.
- The NLP notebook uses its own documented split and training-only upsampling procedure.

For the documented distinction between the report and notebook split descriptions, see [`docs/REPRODUCIBILITY.md`](docs/REPRODUCIBILITY.md).

---

## Results and Supporting Materials

The repository includes:

- Result tables in CSV format
- Visual result summaries
- The final project report
- The project proposal presentation
- Reproducibility documentation

The CSV files in `results/` are provided for convenient inspection and are transcribed from the supplied final project report. The notebooks remain the primary computational artifacts.

---

## Academic Information

**Course:** CSE445 — Machine Learning  
**Department:** Department of Electrical and Computer Engineering, North South University  
**Institution:** North South University

### Authors

**Subroto Ghosh**  
CSE445

**Joy Saha**  
CSE445

### Supervisor

**Dr. Riasat Khan [RtK]**  
Associate Professor  
North South University

---

## Citation

If this repository is referenced in an academic context, please cite the project report included in the `report/` directory.

```text
Ghosh, S. and Saha, J., "Employee Attrition Prediction Using Classical Machine Learning,
Natural Language Processing, and Large Language Models," CSE445 Project Report,
North South University.
```

---

## Limitations and Ethical Considerations

This project is an academic study based on a benchmark HR dataset. The reported models should not be used directly for employment decisions. Real-world deployment would require additional validation, fairness assessment, privacy protection, domain review, and appropriate governance.

---

## License

This project is released under the MIT License. See [`LICENSE`](LICENSE) for details.
