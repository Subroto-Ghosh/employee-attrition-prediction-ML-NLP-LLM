# Reproducibility Notes

This document records the experimental setup represented by the supplied notebooks and final project report.

## Primary Computational Artifacts

- `notebooks/01_full_ml_nlp_llm_pipeline.ipynb` — complete project workflow covering classical ML, NLP/LLM experiments, explainability, and ablation analysis.
- `notebooks/02_nlp_llm_pipeline.ipynb` — focused NLP/LLM workflow covering DistilBERT, BERT, Flan-T5, and TinyLlama.

## Computational Environment

According to the project materials, classical machine learning experiments were performed using CPU-based computation, while transformer/LLM fine-tuning was performed using Google Colab with an NVIDIA T4 GPU.

## Data Availability

The IBM HR dataset is not committed to this repository. Users should obtain the dataset separately and follow the instructions in `data/README.md`.

## Leakage-Control Protocol

The classical workflow applies SMOTE within the cross-validation pipeline. This prevents synthetic samples generated from validation folds from entering the training process for those folds.

For final classical evaluation, decision thresholds are selected using validation data and then fixed before evaluation on the test set.

## Split-Description Consistency Note

The supplied project materials contain two different descriptions of the NLP data split:

1. Parts of the report describe a common stratified 60/20/20 train/validation/test split.
2. The NLP results section describes a 70% training, 15% validation, and 15% test split with training-only upsampling.
3. The supplied NLP notebook explicitly implements the 70/15/15 split.

This repository preserves the supplied materials and does not silently modify the notebooks or reported experimental results to reconcile this difference.

## Results Files

The CSV files under `results/` are transcribed from the supplied final project report for convenient GitHub inspection. They should be treated as supporting result summaries rather than replacements for executing the notebooks.
