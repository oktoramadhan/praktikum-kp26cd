import React from 'react';
import styles from './styles.module.css';

export interface GradingItem {
  title: string;
  percentage: number;
  description?: string;
  color?: string;
  tag?: string;
}

export interface GradingWeightsProps {
  items?: GradingItem[];
}

export const DEFAULT_GRADING_ITEMS: GradingItem[] = [
  {
    title: 'Tugas Mingguan',
    percentage: 40,
    color: '#3b82f6',
  },
  {
    title: 'Responsi',
    percentage: 25,
    color: '#8b5cf6',
  },
  {
    title: 'Keaktifan',
    percentage: 10,
    color: '#10b981',
  },
  {
    title: 'Quiz / Competitive Programming',
    percentage: 25,
    color: '#f59e0b',
  },
];

export default function GradingWeights({
  items = DEFAULT_GRADING_ITEMS,
}: GradingWeightsProps): React.JSX.Element {
  return (
    <div className={styles.container}>
      <div className={styles.grid}>
        {items.map((item, index) => {
          const accentColor = item.color || 'var(--ifm-color-primary)';
          return (
            <div key={index} className={styles.card}>
              <div className={styles.cardTop}>
                <h4 className={styles.cardTitle}>{item.title}</h4>
                <span className={styles.percentage} style={{ color: accentColor }}>
                  {item.percentage}%
                </span>
              </div>

              <div className={styles.progressTrack}>
                <div
                  className={styles.progressBar}
                  style={{
                    width: `${Math.min(Math.max(item.percentage, 0), 100)}%`,
                    backgroundColor: accentColor,
                  }}
                />
              </div>
            </div>
          );
        })}
      </div>
    </div>
  );
}
