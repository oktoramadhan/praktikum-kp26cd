import type {ReactNode} from 'react';
import Heading from '@theme/Heading';
import styles from './styles.module.css';

type FeatureItem = {
  title: string;
  icon: string;
  description: string;
};

const featureList: FeatureItem[] = [
  {
    title: 'Materi Terstruktur',
    icon: '📚',
    description:
      'Materi setiap pertemuan praktikum yang disusun sedemikian rupa untuk bisa diakses kapan saja dan dimana saja.',
  },
  {
    title: 'Penugasan Mingguan',
    icon: '💻',
    description:
      'Tugas praktikum yang dirancang untuk mahasiswa praktek langsung lewat studi kasus yang relevan dengan materi yang dipelajari, sehingga dapat meningkatkan pemahaman dan keterampilan praktis.',
  },
  {
    title: 'Sumber Belajar',
    icon: '🧑‍💻',
    description:
      'Akses ke berbagai referensi, contoh kode, dan tips praktis untuk mendukung proses pembelajaran yang efektif.',
  },
];

const contributors = [
  {name: 'Okto Ramadhan', role: 'Asprak D', github: 'oktoramadhan'},
  {name: 'Andrie Praditya Nugroho', role: 'Asprak C', github: 'andriepraditya47'},
  {name: 'Audrey Jasmine Amadea', role: 'Asprak C', github: 'Audreyja22'},
  {name: 'Imam Alfandiyansa', role: 'Asprak D', github: 'imamalfandiyansa'},
];

export default function HomepageFeatures(): ReactNode {
  return (
    <section className={styles.features}>
      <div className={styles.container}>
        <div className={styles.featureGrid}>
          {featureList.map((feature) => (
            <article className={styles.featureCard} key={feature.title} tabIndex={0}>
              <div className={styles.featureIcon} aria-hidden="true">{feature.icon}</div>
              <Heading as="h3" className={styles.featureTitle}>{feature.title}</Heading>
              <p className={styles.featureDescription}>{feature.description}</p>
            </article>
          ))}
        </div>

        <section className={styles.contributors} aria-labelledby="contributors-heading">
          <Heading as="h2" id="contributors-heading" className={styles.contributorsHeading}>
            ASISTEN PRAKTIKUM 
          </Heading>
          <div className={styles.contributorGrid}>
            {contributors.map(({name, role, github}) => {
              const profileUrl = `https://github.com/${github}`;
              return (
                <article className={styles.contributor} key={github}>
                  <a
                    className={styles.contributorLink}
                    href={profileUrl}
                    target="_blank"
                    rel="noreferrer"
                    aria-label={`Open ${name}'s GitHub profile`}>
                    <img
                      className={styles.avatar}
                      src={`${profileUrl}.png?size=160`}
                      alt={`${name}'s GitHub profile`}
                      width="80"
                      height="80"
                    />
                    <Heading as="h3" className={styles.contributorName}>{name}</Heading>
                    <p className={styles.contributorRole}>{role}</p>
                  </a>
                </article>
              );
            })}
          </div>
        </section>
      </div>
    </section>
  );
}
