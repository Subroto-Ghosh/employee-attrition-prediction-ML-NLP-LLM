# Results Summary

The following values summarize the reported project results. The tables in this document are provided for convenient reference; the supplied notebooks and final report remain the primary sources.

## Best Classical Model

The Stacking Ensemble achieved the highest reported test F1-score among the classical models.

| Metric | Score |
|---|---:|
| Accuracy | 0.8593 |
| Precision | 0.5254 |
| Recall | 0.6596 |
| F1-score | 0.5849 |
| ROC-AUC | 0.7989 |

## Best NLP / LLM Model

TinyLlama-1.1B achieved the highest reported F1-score and ROC-AUC among the evaluated NLP/LLM models.

| Model | Accuracy | Precision | Recall | F1-score | ROC-AUC |
|---|---:|---:|---:|---:|---:|
| TinyLlama-1.1B | 0.8235 | 0.4571 | 0.4444 | 0.4507 | 0.7995 |
| BERT-base | 0.7466 | 0.3438 | 0.6111 | 0.4400 | 0.7566 |
| DistilBERT | 0.8281 | 0.4615 | 0.3333 | 0.3871 | 0.7790 |
| Flan-T5-base | 0.4932 | 0.2031 | 0.7222 | 0.3171 | 0.6682 |

## Ablation Study

| Configuration | Test F1-score |
|---|---:|
| Full configuration | 0.5849 |
| Without ensembling | 0.5120 |
| Without hyperparameter tuning | 0.4792 |
| Without SMOTE | 0.4462 |
